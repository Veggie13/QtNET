#pragma once

#pragma warning (disable:4561 4679 4944)


#include <msclr/marshal.h>
#include "Wrapper.h"
#include "MacroHelpers.h"

#define DLL_NAME(x) MACRO(QtNET) ## NET ## x ##.dll

#define QtNET_CORE COMBINE_PATH(_BASE_REF_PATH,DLL_NAME(Core))
#define QtNET_WIDGETS COMBINE_PATH(_BASE_REF_PATH,DLL_NAME(Widgets))

#ifdef QT_NAMESPACE
#define NATIVE(x) QT_NAMESPACE :: x
#else
#define NATIVE(x) :: x
#endif
#define LIB_CLASS(lib, x) QtNET :: lib :: x
#define LOCAL(x) LIB_CLASS(CURRENT_LIB, x)
#define QTNET_BEGIN namespace QtNET { void dummy()
#define QTNET_END }
#define QTNET_NAMESPACE(x) QTNET_BEGIN; namespace x { void dummy2()
#define NAMESPACE_BEGIN QTNET_NAMESPACE(CURRENT_LIB)
#define NAMESPACE_END QTNET_END }
#define USING_ROOT using namespace QtNET
#define USING(x) USING_ROOT :: x
#define LOCALIZE(LIB, NAME) typedef LIB_CLASS(LIB, NAME) NAME
#define NATIVE_FWD(x) QT_FORWARD_DECLARE_CLASS(x)
#define LOCAL_FWD(x) NAMESPACE_BEGIN; x; NAMESPACE_END

#define Q_OBJECT_PREPARE typedef NATIVE(QString) QString;

#define QN_OBJ LIB_CLASS(Core, QObject)
#define QN_STR LIB_CLASS(Core, QString)
