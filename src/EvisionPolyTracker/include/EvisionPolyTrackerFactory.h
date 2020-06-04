#include <QtCore/qglobal.h>
#include <QWidget>
//EvisionPolyTracker EVISIONPOLYTRACKER
#ifndef BUILD_STATIC
# if defined( EVISIONPOLYTRACKERFACTORY_LIB)
#  define  EVISIONPOLYTRACKERFACTORY_EXPORT Q_DECL_EXPORT
# else
#  define  EVISIONPOLYTRACKERFACTORY_EXPORT Q_DECL_IMPORT
# endif
#else
# define EVISIONPOLYTRACKERFACTORY_EXPORT
#endif

class EVISIONPOLYTRACKERFACTORY_EXPORT EvisionPolyTrackerFactory
{
public:
	EvisionPolyTrackerFactory();
	static QWidget* CreateEvisionPolyTrackerViewer(QWidget* parent = Q_NULLPTR);
};