#include "EvisionTraceFactory.h"
#include "TraceView.h"

EvisionTraceFactory::EvisionTraceFactory()
{
}

QWidget* EvisionTraceFactory::CreateEvisionTraceView(QWidget* parent)
{
	TraceView* m_Trace = new TraceView(parent);
	return m_Trace;
}
