#pragma once

#pragma managed (push, off)
#include <QtCore/QMap>
#pragma managed (pop)

namespace helper
{
    class NativeMapItem
    {
        gcroot<System::Object^> _item;
    public:
        NativeMapItem();
        NativeMapItem(gcroot<System::Object^>);
        friend bool operator < (const NativeMapItem&, const NativeMapItem&);
        gcroot<System::Object^> Item();
    };

    bool operator < (const NativeMapItem&, const NativeMapItem&);
}

NAMESPACE_BEGIN;

generic <typename KeyT, typename ValueT>
public ref class QMap
    :   public NativeWrapper< NATIVE(MACRO(QMap<::helper::NativeMapItem, ::helper::NativeMapItem>)) >
    ,   public System::Collections::Generic::IDictionary<KeyT, ValueT>
{
    typedef LOCAL(MACRO(QMap<KeyT, ValueT>)) CurrT;
    typedef System::Collections::IEnumerator EnumeratorI;
    typedef System::Collections::IEnumerable EnumerableI;
    typedef System::Collections::Generic::KeyValuePair<KeyT, ValueT> KVP;
    typedef System::Collections::Generic::IDictionary<KeyT, ValueT> DictI;
    typedef System::Collections::Generic::ICollection<KeyT> KeyCollectionI;
    typedef System::Collections::Generic::ICollection<ValueT> ValueCollectionI;
    typedef System::Collections::Generic::IEnumerable<KVP> EnumerableG;
    typedef System::Collections::Generic::IEnumerator<KVP> EnumeratorG;

public:
    QMap();
    QMap(DictI^);
    QMap(CurrT^);

    property int Size { int get(); }
    property bool IsEmpty { bool get(); }
    property bool IsDetached { bool get(); }
    property bool Sharable { void set(bool); }

    void detach();
    bool isSharedWith(CurrT^);
    
    void clear();

    int remove(KeyT);
    ValueT take(KeyT);

    bool contains(KeyT);

    // QList stuff maybe

#pragma region IDictionary<>
#pragma region ICollection<>
#pragma region IEnumerable<>
#pragma region IEnumerable
    virtual EnumeratorI^ EnumerableGetEnumerator() = EnumerableI::GetEnumerator;
#pragma endregion

    virtual EnumeratorG^ GetEnumerator();
#pragma endregion

    property int Count { virtual int get(); }
    property bool IsReadOnly { virtual bool get(); }

    virtual void Add(KVP);
    virtual void Clear();
    virtual bool Contains(KVP);
    virtual void CopyTo(array<KVP>^, int);
    virtual bool Remove(KVP);
#pragma endregion

    property ValueT default[KeyT]
    {
        virtual ValueT get(KeyT);
        virtual void set(KeyT, ValueT);
    }

    property KeyCollectionI^ Keys { virtual KeyCollectionI^ get(); }
    property ValueCollectionI^ Values { virtual ValueCollectionI^ get(); }

    virtual bool ContainsKey(KeyT);
    virtual void Add(KeyT, ValueT);
    virtual bool Remove(KeyT);
    virtual bool TryGetValue(KeyT, ValueT%);
#pragma endregion
};

NAMESPACE_END;
