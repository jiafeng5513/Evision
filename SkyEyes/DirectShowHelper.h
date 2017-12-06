#pragma once

#include <dshow.h>
#include <vector>
#include <string>

class DirectShowHelper
{
public:
	DirectShowHelper(void);
	~DirectShowHelper(void);

public:
	void enumerateDevices(const IID& deviceClass, std::vector<std::wstring>& devices);
	void enumerateMediaTypes(const WCHAR* device, const IID& deviceClass, std::vector<AM_MEDIA_TYPE*>& mediaTypes);
	void enumerateMediaTypes(IPin* pin, std::vector<AM_MEDIA_TYPE*>& mediaTypes);

	HRESULT createFilterGraph(IFilterGraph** graph);
	HRESULT createGraphBuilder(IGraphBuilder** builder);
	HRESULT createFilter(REFCLSID clsid, IBaseFilter** filter);
	HRESULT createFilter(const WCHAR* friendlyName, const IID& deviceClass, IBaseFilter** filter);
	HRESULT connectFilters(IGraphBuilder* builder, IBaseFilter* first, IBaseFilter* second);
	HRESULT setFilterFormat(AM_MEDIA_TYPE* format, IBaseFilter* filter);

	HRESULT getPin(IBaseFilter * pFilter, PIN_DIRECTION dirrequired, int iNum, IPin **ppPin);
	HRESULT getUnconnectedPin(IBaseFilter* filter, PIN_DIRECTION dir, IPin** pin);

	HRESULT AddToRot(IUnknown *pUnkGraph, DWORD *pdwRegister);
	void RemoveFromRot(DWORD pdwRegister);

	void deleteMediaType(AM_MEDIA_TYPE* mt);

	const std::wstring getLastError();

private:
	std::wstring mLastError;

private:
	void setLastError(WCHAR* text);
};
