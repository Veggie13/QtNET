#pragma once

namespace QtNET {

    template <class NativeT>
    NativeT* nativeDefault() { return new NativeT; }
    
    template <class NativeT>
    struct NativeInitializer
    {
        static NativeT* init() { return nativeDefault<NativeT>(); }
        template <typename T1>
        static NativeT* init(T1 a1) { return new NativeT(a1); }
        template <typename T1, typename T2>
        static NativeT* init(T1 a1, T2 a2) { return new NativeT(a1, a2); }
        template <typename T1, typename T2, typename T3>
        static NativeT* init(T1 a1, T2 a2, T3 a3) { return new NativeT(a1, a2, a3); }
        template <typename T1, typename T2, typename T3, typename T4>
        static NativeT* init(T1 a1, T2 a2, T3 a3, T4 a4) { return new NativeT(a1, a2, a3, a4); }
    };

#define DISABLE_DEFAULT(CLASS_NAME) template <> \
        CLASS_NAME * QtNET::nativeDefault< NATIVE(CLASS_NAME) >() { return NULL; }

    template <class NT>
    public ref class NativeWrapper
    {
        bool _destroy;
        bool _isDisposed;
        NT* _native;

    public:
        typedef NT NativeT;
        typedef NativeWrapper<NativeT> WrapperT;

    protected:
        NativeWrapper(NativeT* native, bool destroy) : _destroy(destroy), _isDisposed(false), _native(native) {}
        NativeWrapper() : _destroy(true), _isDisposed(false), _native(NativeInitializer<NativeT>::init()) {}
        template <typename T1>
        NativeWrapper(T1 a1) : _destroy(true), _isDisposed(false), _native(NativeInitializer<NativeT>::init(a1)) {}
        template <typename T1, typename T2>
        NativeWrapper(T1 a1, T2 a2) : _destroy(true), _isDisposed(false), _native(NativeInitializer<NativeT>::init(a1, a2)) {}
        template <typename T1, typename T2, typename T3>
        NativeWrapper(T1 a1, T2 a2, T3 a3) : _destroy(true), _isDisposed(false), _native(NativeInitializer<NativeT>::init(a1, a2, a3)) {}
        template <typename T1, typename T2, typename T3, typename T4>
        NativeWrapper(T1 a1, T2 a2, T3 a3, T4 a4) : _destroy(true), _isDisposed(false), _native(NativeInitializer<NativeT>::init(a1, a2, a3, a4)) {}

        virtual void disposeManaged() {}

    public:
        virtual ~NativeWrapper()
        {
            if (!_destroy && _isDisposed) return;
            disposeManaged();
            this->!NativeWrapper();
            _isDisposed = true;
        }

        !NativeWrapper()
        {
            if (_destroy) delete _native;
            _native = NULL;
        }

    internal:
        NativeT& ref() { return *_native; }
        NativeT* ptr() { return _native; }
    };

    template <typename BaseT, typename BNT, class NT>
    public ref class NativeInheritWrapper : BaseT
    {
    public:
        typedef NT NativeT;
        typedef BNT BaseNativeT;
        typedef NativeInheritWrapper<BaseT, BNT, NT> WrapperT;

    protected:
        NativeInheritWrapper() : BaseT(new NativeT(), true) {}
        NativeInheritWrapper(NativeT* native, bool destroy) : BaseT(native, destroy) {}
        template <typename T1>
        NativeInheritWrapper(T1 a1) : BaseT(new NativeT(a1), true) {}
        template <typename T1, typename T2>
        NativeInheritWrapper(T1 a1, T2 a2) : BaseT(new NativeT(a1, a2), true) {}
        template <typename T1, typename T2, typename T3>
        NativeInheritWrapper(T1 a1, T2 a2, T3 a3) : BaseT(new NativeT(a1, a2, a3), true) {}
        template <typename T1, typename T2, typename T3, typename T4>
        NativeInheritWrapper(T1 a1, T2 a2, T3 a3, T4 a4) : BaseT(new NativeT(a1, a2, a3, a4), true) {}

    internal:
        NativeT& ref() { return dynamic_cast<NativeT&>(BaseT::ref()); }
        NativeT* ptr() { return dynamic_cast<NativeT*>(BaseT::ptr()); }
    };

}

#define WRAPPER(x) public ref class x : NativeWrapper<NATIVE(x)>
#define INHERIT_WRAPPER(x,y) public ref class x : NativeInheritWrapper<LOCAL(y), NATIVE(y), NATIVE(x)>
#define INHERIT_EXT_WRAPPER(x,lib,y) public ref class x : NativeInheritWrapper<LIB_CLASS(lib,y), NATIVE(y), NATIVE(x)>
