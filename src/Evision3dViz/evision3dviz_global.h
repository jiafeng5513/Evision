#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(EVISION3DVIZ_LIB)
#  define EVISION3DVIZ_EXPORT Q_DECL_EXPORT
# else
#  define EVISION3DVIZ_EXPORT Q_DECL_IMPORT
# endif
#else
# define EVISION3DVIZ_EXPORT
#endif
