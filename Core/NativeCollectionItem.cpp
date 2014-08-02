#include "QtNET.h"

#include "NativeCollectionItem.h"

using namespace System;
using namespace System::Linq;
using namespace System::Collections::Generic;
using namespace System::Reflection;
using namespace helper;


ref class ComparableComparison : IObjectComparison
{
    MethodInfo^ _methodInfo;
public:
    ComparableComparison(MethodInfo^ methodInfo) : _methodInfo(methodInfo) {}

    virtual int Compare(Object^ a, Object^ b)
    {
        return (int)_methodInfo->Invoke(a, gcnew array<Object^>{b});
    }
};

ref class HashCodeComparison : IObjectComparison
{
public:
    virtual int Compare(Object^ a, Object^ b)
    {
        if (a == nullptr || b == nullptr)
        {
            throw gcnew InvalidOperationException();
        }

        int ah = a->GetHashCode();
        int bh = b->GetHashCode();
        if (ah < bh)
        {
            return -1;
        }
        if (ah > bh)
        {
            return 1;
        }
        return 0;
    }
};

ref class NullComparison : IObjectComparison
{
public:
    virtual int Compare(Object^ a, Object^ b)
    {
        throw gcnew InvalidOperationException();
    }
};

NativeCollectionItem::NativeCollectionItem()
    :   _item(nullptr)
    ,   _compare( gcnew NullComparison() )
{
}

NativeCollectionItem::NativeCollectionItem(
    gcroot<Type^> type,
    gcroot<Object^> obj
)
    :   _item(obj)
    ,   _compare( Comparison(type) )
{
}

NativeCollectionItem::NativeCollectionItem(
    gcroot<IObjectComparison^> compare,
    gcroot<Object^> obj
)
    :   _item(obj)
    ,   _compare( compare )
{
}

gcroot<Object^> NativeCollectionItem::Item() const
{
    return _item;
}

bool IsComparable(Type^ type)
{
    Type^ comparableType = System::IComparable<int>::typeid->GetGenericTypeDefinition();
    return type->IsGenericType &&
        type->GetGenericTypeDefinition()->Equals(comparableType);
}

gcroot<IObjectComparison^> NativeCollectionItem::Comparison(gcroot<Type^> type)
{
    Type^ t = type;
    Func<Type^, bool>^ isComparableDel = gcnew Func<Type^, bool>(IsComparable);

    auto comparableInterfaces = Enumerable::Where<Type^>(t->GetInterfaces(), isComparableDel);
    for each (Type^ iface in comparableInterfaces)
    {
        if (iface->GetGenericArguments()[0]->IsAssignableFrom(t))
        {
            MethodInfo^ info = iface->GetMethod("CompareTo");
            return gcnew ComparableComparison(info);
        }
    }

    return gcnew HashCodeComparison();
}

bool ::helper::operator < (const NativeCollectionItem& a, const NativeCollectionItem& b)
{
    Object^ oa = a.Item();
    Object^ ob = b.Item();
    return (a._compare->Compare(oa, ob) < 0);
}

bool ::helper::operator == (const NativeCollectionItem& a, const NativeCollectionItem& b)
{
    return a._item->Equals(b._item);
}
