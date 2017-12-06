#include "StdAfx.h"
#include "DirectShowHelper.h"
//#include "strutil.h"

DirectShowHelper::DirectShowHelper(void)
{
}

DirectShowHelper::~DirectShowHelper(void)
{
}

HRESULT DirectShowHelper::AddToRot(IUnknown *pUnkGraph, DWORD *pdwRegister)
{
	IMoniker * pMoniker;
	IRunningObjectTable *pROT;
	if (FAILED(GetRunningObjectTable(0, &pROT))) {
		return E_FAIL;
	}
	WCHAR wsz[256];
	wsprintfW(wsz, L"FilterGraph %08x pid %08x", (DWORD_PTR)pUnkGraph, GetCurrentProcessId());
	HRESULT hr = CreateItemMoniker(L"!", wsz, &pMoniker);
	if (SUCCEEDED(hr)) {
		hr = pROT->Register(ROTFLAGS_REGISTRATIONKEEPSALIVE, pUnkGraph,
			pMoniker, pdwRegister);
		pMoniker->Release();
	}
	pROT->Release();
	return hr;
}

void DirectShowHelper::RemoveFromRot(DWORD pdwRegister)
{
	IRunningObjectTable *pROT;
	if (SUCCEEDED(GetRunningObjectTable(0, &pROT))) {
		pROT->Revoke(pdwRegister);
		pROT->Release();
	}
}

void DirectShowHelper::enumerateDevices(const IID& deviceClass, std::vector<std::wstring>& devices)
{
	CComPtr<ICreateDevEnum> deviceEnum;
	CComPtr<IEnumMoniker> enumMoniker;
	CComPtr<IMoniker> moniker;
	HRESULT hr;

	hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER,
		IID_ICreateDevEnum, (void**)&deviceEnum);
	if (FAILED(hr)) {
		setLastError(L"Failed: CreateDevEnum");
		return;
	}

	hr = deviceEnum->CreateClassEnumerator(deviceClass, &enumMoniker, 0);
	if (hr != S_OK) {
		setLastError(L"Failed: CreateClassEnumerator");
		return;
	}

	ULONG fetched;

	while (moniker.Release(), enumMoniker->Next(1, &moniker, &fetched) == S_OK) {
		CComPtr<IPropertyBag> propertyBag;
		ASSERT(moniker);

		do {
			hr = moniker->BindToStorage(0, 0, IID_IPropertyBag, (void**)&propertyBag);
			if (FAILED(hr))
				break;

			VARIANT var;
			var.vt = VT_BSTR;
			hr = propertyBag->Read(L"FriendlyName", &var, 0);
			if (FAILED(hr))
				break;

			std::wstring name = var.bstrVal;
			SysFreeString(var.bstrVal);
			/*
			hr = propertyBag->Read(L"CLSID", &var, 0);
			if (FAILED(hr))
			break;

			CLSID clsid;
			hr = CLSIDFromString(var.bstrVal, &clsid);
			SysFreeString(var.bstrVal);
			if (FAILED(hr))
			break;
			*/
			devices.push_back(name);
		} while (0);
	}
}

void DirectShowHelper::enumerateMediaTypes(const WCHAR* device, const IID& deviceClass, std::vector<AM_MEDIA_TYPE*>& mediaTypes)
{
	CComPtr<IBaseFilter> filter;
	HRESULT hr;

	hr = createFilter(device, deviceClass, &filter);
	if (FAILED(hr))
		return;
	if (filter == 0)
		return;

	// Enumerate Pin
	CComPtr<IEnumPins> enumPins;
	hr = filter->EnumPins(&enumPins);
	if (FAILED(hr)) {
		return;
	}
	if (filter == 0)
		return;

	// Find the output Pin
	CComPtr<IPin> pin;
	while (pin.Release(), enumPins->Next(1, &pin, 0) == S_OK) {
		PIN_DIRECTION direction;
		pin->QueryDirection(&direction);
		if (direction == PINDIR_OUTPUT) {
			enumerateMediaTypes(pin, mediaTypes);
		}
	}
}

void DirectShowHelper::enumerateMediaTypes(IPin* pin, std::vector<AM_MEDIA_TYPE*>& mediaTypes)
{
	if (pin == 0)
		return;

	CComPtr<IEnumMediaTypes> enumMediaTypes;
	HRESULT hr;

	hr = pin->EnumMediaTypes(&enumMediaTypes);
	if (FAILED(hr))
		return;

	AM_MEDIA_TYPE* mt;
	while (enumMediaTypes->Next(1, &mt, 0) == S_OK) {
		mediaTypes.push_back(mt);
	}
}

HRESULT DirectShowHelper::createFilterGraph(IFilterGraph** graph)
{
	HRESULT hr;

	if (graph == 0)
		return E_POINTER;

	hr = CoCreateInstance(CLSID_FilterGraph, // get the graph object
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IFilterGraph,
		(void **)graph);

	if (FAILED(hr)) {
		TRACE("CreateFilterGraph: Failed to create graph!  hr=0x%x\n", hr);
		return hr;
	}

	return S_OK;
}

HRESULT DirectShowHelper::createGraphBuilder(IGraphBuilder** builder)
{
	HRESULT hr;

	if (builder == 0)
		return E_POINTER;

	hr = CoCreateInstance(CLSID_FilterGraph, // get the graph object
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IGraphBuilder,
		(void **)builder);

	if (FAILED(hr)) {
		TRACE("CreateFilterGraph: Failed to create graph!  hr=0x%x\n", hr);
		return hr;
	}

	return S_OK;
}

HRESULT DirectShowHelper::createFilter(REFCLSID clsid, IBaseFilter** filter)
{
	HRESULT hr;

	hr = CoCreateInstance(clsid,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IBaseFilter,
		(void **)filter);

	if (FAILED(hr)) {
		TRACE("CreateFilter: Failed to create filter!  hr=0x%x\n", hr);
		return hr;
	}

	return S_OK;
}

HRESULT DirectShowHelper::createFilter(const WCHAR* friendlyName, const IID& deviceClass, IBaseFilter** filter)
{
	CComPtr<ICreateDevEnum> deviceEnum;
	CComPtr<IEnumMoniker> enumMoniker;
	CComPtr<IMoniker> moniker;
	HRESULT hr;

	hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC,
		IID_ICreateDevEnum, (void**)&deviceEnum);
	if (FAILED(hr)) {
		setLastError(L"Failed: CreateDevEnum");
		return E_FAIL;
	}

	hr = deviceEnum->CreateClassEnumerator(deviceClass, &enumMoniker, 0);
	if (FAILED(hr)) {
		setLastError(L"Failed: CreateClassEnumerator");
		return E_FAIL;
	}

	ULONG fetched;
	bool isFound = false;
	std::wstring target(friendlyName);

	while (!isFound && enumMoniker && enumMoniker->Next(1, &(moniker.p), &fetched) == S_OK) {
		CComPtr<IPropertyBag> propertyBag;
		ASSERT(moniker);

		do {
			hr = moniker->BindToStorage(0, 0, IID_IPropertyBag, (void**)&propertyBag);
			if (FAILED(hr))
				break;

			VARIANT var;
			var.vt = VT_BSTR;
			hr = propertyBag->Read(L"FriendlyName", &var, 0);
			if (FAILED(hr))
				break;

			std::wstring name = var.bstrVal;
			SysFreeString(var.bstrVal);

			hr = E_FAIL;
			if (name.compare(target) == 0) {
				hr = moniker->BindToObject(NULL, NULL, IID_IBaseFilter, (void**)filter);
				if (FAILED(hr))
					break;
				isFound = true;
				hr = S_OK;
			}
		} while (0);
		moniker.Release();
	}

	return hr;
}

void DirectShowHelper::deleteMediaType(AM_MEDIA_TYPE* mt)
{
	if (mt == 0)
		return;

	if (mt->cbFormat != 0) {
		CoTaskMemFree((LPVOID)mt->pbFormat);
		mt->pbFormat = 0;
	}

	if (mt->pUnk != NULL)
		mt->pUnk->Release();
	CoTaskMemFree((LPVOID)mt);
}

HRESULT DirectShowHelper::setFilterFormat(AM_MEDIA_TYPE* format, IBaseFilter* filter)
{
	CComPtr<IPin> pin;

	HRESULT hr;

	do {
		hr = getPin(filter, PINDIR_OUTPUT, 0, &pin);
		if (FAILED(hr))
			break;

		CComPtr<IAMStreamConfig> streamConfig;
		hr = pin->QueryInterface(IID_IAMStreamConfig, (void**)&streamConfig);
		if (SUCCEEDED(hr)) {
			hr = streamConfig->SetFormat(format);
			if (SUCCEEDED(hr)) {
				return S_OK;
			}
		}
	} while (0);

	return E_FAIL;
}

HRESULT DirectShowHelper::getPin(IBaseFilter* filter, PIN_DIRECTION dirrequired, int iNum, IPin** pin)
{
	CComPtr< IEnumPins > enumPins;
	*pin = NULL;

	HRESULT hr = filter->EnumPins(&enumPins);
	if (FAILED(hr))  return hr;

	ULONG ulFound;
	IPin *newPin;
	hr = E_FAIL;

	while (S_OK == enumPins->Next(1, &newPin, &ulFound)) {
		PIN_DIRECTION pindir = (PIN_DIRECTION)3;
		newPin->QueryDirection(&pindir);
		if (pindir == dirrequired) {
			if (iNum == 0) {
				*pin = newPin;  // Return the pin's interface
				hr = S_OK;      // Found requested pin, so clear error
				break;
			}
			iNum--;
		}
		newPin->Release();
	}

	return hr;
}

HRESULT DirectShowHelper::getUnconnectedPin(IBaseFilter* filter, PIN_DIRECTION dir, IPin** pin)
{
	CComPtr<IPin> connectedPin;
	HRESULT hr;
	int num = 0;

	do {
		hr = getPin(filter, dir, num++, pin);
		if (FAILED(hr))
			return E_FAIL;

		hr = (*pin)->ConnectedTo(&connectedPin);
		if (hr == VFW_E_NOT_CONNECTED)
			break;

		(*pin)->Release();
		connectedPin.Release();
	} while (1);

	return S_OK;
}

HRESULT DirectShowHelper::connectFilters(IGraphBuilder* builder, IBaseFilter* first, IBaseFilter* second)
{
	CComPtr<IPin> outPin;
	CComPtr<IPin> inPin;

	HRESULT hr;

	do {
		hr = getUnconnectedPin(first, PINDIR_OUTPUT, &outPin);
		if (FAILED(hr))
			break;

		hr = getUnconnectedPin(second, PINDIR_INPUT, &inPin);
		if (FAILED(hr))
			break;

		hr = builder->Connect(outPin, inPin);
		if (FAILED(hr))
			break;

		return S_OK;
	} while (0);

	return hr;
}

void DirectShowHelper::setLastError(WCHAR* text)
{
	mLastError = text;
}

const std::wstring DirectShowHelper::getLastError()
{
	return mLastError;
}