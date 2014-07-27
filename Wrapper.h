#pragma once

namespace QtNET {

    template <class NativeT>
    NativeT* nativeDefault() { return new NativeT; }
    
    template <class NativeT, class OutT = NativeT>
    struct NativeInitializer
    {
        static OutT* init() { return nativeDefault<NativeT>(); }
        template <typename T1>
        static OutT* init(T1 a1) { return new NativeT(a1); }
        template <typename T1, typename T2>
        static OutT* init(T1 a1, T2 a2) { return new NativeT(a1, a2); }
        template <typename T1, typename T2, typename T3>
        static OutT* init(T1 a1, T2 a2, T3 a3) { return new NativeT(a1, a2, a3); }
        template <typename T1, typename T2, typename T3, typename T4>
        static OutT* init(T1 a1, T2 a2, T3 a3, T4 a4) { return new NativeT(a1, a2, a3, a4); }
    };

    template <typename NativeT>
    struct NullDeleter
    {
        void operator()(NativeT*) {}
    };

#define DISABLE_DEFAULT(CLASS_NAME) template <> \
        NATIVE(CLASS_NAME) * QtNET::nativeDefault< NATIVE(CLASS_NAME) >() { return NULL; }

    template <class NT>
    public ref class NativeWrapper
    {
    public:
        typedef NT NativeT;
        typedef NativeWrapper<NativeT> WrapperT;
        typedef std::shared_ptr<NativeT> PtrT;

    private:
        bool _isDisposed;
        PtrT* _native;

    protected:
        NativeWrapper(NativeT* native) : _isDisposed(false), _native(new PtrT(native, NullDeleter<NT>())) {}
        NativeWrapper(NativeT& native) : _isDisposed(false), _native(new PtrT(&native, NullDeleter<NT>())) {}
        NativeWrapper() : _isDisposed(false), _native(new PtrT(NativeInitializer<NativeT>::init())) {}
        template <typename T1>
        NativeWrapper(T1 a1) : _isDisposed(false), _native(new PtrT(NativeInitializer<NativeT>::init(a1))) {}
        template <typename T1, typename T2>
        NativeWrapper(T1 a1, T2 a2) : _isDisposed(false), _native(new PtrT(NativeInitializer<NativeT>::init(a1, a2))) {}
        template <typename T1, typename T2, typename T3>
        NativeWrapper(T1 a1, T2 a2, T3 a3) : _isDisposed(false), _native(new PtrT(NativeInitializer<NativeT>::init(a1, a2, a3))) {}
        template <typename T1, typename T2, typename T3, typename T4>
        NativeWrapper(T1 a1, T2 a2, T3 a3, T4 a4) : _isDisposed(false), _native(new PtrT(NativeInitializer<NativeT>::init(a1, a2, a3, a4))) {}

        virtual void disposeManaged() {}

    public:
        virtual ~NativeWrapper()
        {
            if (_isDisposed) return;
            disposeManaged();
            this->!NativeWrapper();
            _isDisposed = true;
        }

        !NativeWrapper()
        {
            if (_native) delete _native;
            _native = NULL;
        }

    internal:
        NativeT& ref() { return **_native; }
        NativeT* ptr() { return _native->get(); }
    };

    template <typename BaseT, typename BNT, class NT>
    public ref class NativeInheritWrapper : BaseT
    {
    public:
        typedef NT NativeT;
        typedef BNT BaseNativeT;
        typedef NativeInheritWrapper<BaseT, BNT, NT> WrapperT;

    protected:
        NativeInheritWrapper(NativeT* native) : BaseT(native) {}
        NativeInheritWrapper(NativeT& native) : BaseT(native) {}
        NativeInheritWrapper() : BaseT(NativeInitializer<NativeT, BaseNativeT>::init()) {}
        template <typename T1>
        NativeInheritWrapper(T1 a1) : BaseT(NativeInitializer<NativeT, BaseNativeT>::init(a1)) {}
        template <typename T1, typename T2>
        NativeInheritWrapper(T1 a1, T2 a2) : BaseT(NativeInitializer<NativeT, BaseNativeT>::init(a1, a2)) {}
        template <typename T1, typename T2, typename T3>
        NativeInheritWrapper(T1 a1, T2 a2, T3 a3) : BaseT(NativeInitializer<NativeT, BaseNativeT>::init(a1, a2, a3)) {}
        template <typename T1, typename T2, typename T3, typename T4>
        NativeInheritWrapper(T1 a1, T2 a2, T3 a3, T4 a4) : BaseT(NativeInitializer<NativeT, BaseNativeT>::init(a1, a2, a3, a4)) {}

    internal:
        NativeT& ref() { return dynamic_cast<NativeT&>(BaseT::ref()); }
        NativeT* ptr() { return dynamic_cast<NativeT*>(BaseT::ptr()); }
    };

}

#define WRAPPER(x) public ref class x : NativeWrapper<NATIVE(x)>
#define INHERIT_WRAPPER(x,y) public ref class x : NativeInheritWrapper<LOCAL(y), NATIVE(y), NATIVE(x)>
#define INHERIT_EXT_WRAPPER(x,lib,y) public ref class x : NativeInheritWrapper<LIB_CLASS(lib,y), NATIVE(y), NATIVE(x)>
