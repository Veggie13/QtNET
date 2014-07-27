#include "QtNET.h"

#include "QApplication.h"

using namespace System;
using namespace System::Linq;


NAMESPACE_BEGIN;

QApplication::QApplication(array<String^>^ args)
    :   NativeWrapper(init(args))
{
}

int QApplication::exec()
{
    return ref().exec();
}

NATIVE(QApplication)* QApplication::init(array<String^>^ args)
{
    using namespace System::Runtime::InteropServices;

    int argc = args->Length;
    auto argsa = gcnew array<IntPtr>(argc);
            
    msclr::interop::marshal_context context;
    for (int i = 0; i < argc; i++)
    {
        int len = args[i]->Length + 1;
        char* ss = new char[len];
        const char* s = context.marshal_as<const char*>(args[i]);
        memcpy(ss, s, len);
        argsa[i] = IntPtr(ss);
    }

    GCHandle hdl = GCHandle::Alloc(argsa, GCHandleType::Pinned);
    char** argv = NULL;
    try
    {
        argv = (char**)(void*)hdl.AddrOfPinnedObject();
        return new NATIVE(QApplication)(argc, argv);
    }
    finally
    {
        for (int i = 0; i < argc; i++)
        {
            delete[] argsa[i];
        }
        hdl.Free();
    }
}

NAMESPACE_END;
