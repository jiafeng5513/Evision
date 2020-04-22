#pragma once

#include <QtCore/qglobal.h>
#include <string>
#include <QWidget>
// EvisionDisparityFactory EVISIONDISPARITYFACTORY
#ifndef BUILD_STATIC
# if defined( EVISIONDISPARITYFACTORY_LIB)
#  define  EVISIONDISPARITYFACTORY_EXPORT Q_DECL_EXPORT
# else
#  define  EVISIONDISPARITYFACTORY_EXPORT Q_DECL_IMPORT
# endif
#else
# define EVISIONDISPARITYFACTORY_EXPORT
#endif
class EVISIONDISPARITYFACTORY_EXPORT EvisionDisparityFactory
{
public:
	EvisionDisparityFactory();
	static QWidget* CreateEvisionDisparity(QWidget* parent = Q_NULLPTR);
};
