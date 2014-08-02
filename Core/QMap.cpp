#include "QtNET.h"

#include "QList.h"
#include "QMap.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace helper;

NAMESPACE_BEGIN;

generic <typename KeyT, typename ValueT>
QMap<KeyT, ValueT>::QMap()
    :   NativeWrapper()
    ,   _keyCompare( NativeCollectionItem::Comparison(KeyT::typeid) )
    ,   _valCompare( NativeCollectionItem::Comparison(ValueT::typeid) )
{
}

generic <typename KeyT, typename ValueT>
QMap<KeyT, ValueT>::QMap(DictI^)
    :   NativeWrapper()
    ,   _keyCompare( NativeCollectionItem::Comparison(KeyT::typeid) )
    ,   _valCompare( NativeCollectionItem::Comparison(ValueT::typeid) )
{
    throw gcnew NotImplementedException();
}

generic <typename KeyT, typename ValueT>
QMap<KeyT, ValueT>::QMap(CurrT^ other)
    :   NativeWrapper(other->ref())
    ,   _keyCompare(other->_keyCompare)
    ,   _valCompare(other->_valCompare)
{
}

generic <typename KeyT, typename ValueT>
int QMap<KeyT, ValueT>::Size::get()
{
    return ref().size();
}

generic <typename KeyT, typename ValueT>
bool QMap<KeyT, ValueT>::IsEmpty::get()
{
    return ref().isEmpty();
}

generic <typename KeyT, typename ValueT>
bool QMap<KeyT, ValueT>::IsDetached::get()
{
    return ref().isDetached();
}

generic <typename KeyT, typename ValueT>
void QMap<KeyT, ValueT>::Sharable::set(bool val)
{
    ref().setSharable(val);
}

generic <typename KeyT, typename ValueT>
void QMap<KeyT, ValueT>::detach()
{
    ref().detach();
}

generic <typename KeyT, typename ValueT>
bool QMap<KeyT, ValueT>::isSharedWith(CurrT^ other)
{
    return ref().isSharedWith(other->ref());
}
    
generic <typename KeyT, typename ValueT>
void QMap<KeyT, ValueT>::clear()
{
    ref().clear();
}

generic <typename KeyT, typename ValueT>
int QMap<KeyT, ValueT>::remove(KeyT key)
{
    return ref().remove(NativeCollectionItem(_keyCompare, key));
}

generic <typename KeyT, typename ValueT>
ValueT QMap<KeyT, ValueT>::take(KeyT key)
{
    Object^ taken = ref().take(NativeCollectionItem(_keyCompare, key)).Item();
    return (ValueT)taken;
}

generic <typename KeyT, typename ValueT>
bool QMap<KeyT, ValueT>::contains(KeyT key)
{
    return ref().contains(NativeCollectionItem(_keyCompare, key));
}

generic <typename KeyT, typename ValueT>
QList<KeyT>^ QMap<KeyT, ValueT>::uniqueKeys()
{
    return gcnew QList<KeyT>( _keyCompare, ref().uniqueKeys() );
}

generic <typename KeyT, typename ValueT>
QList<KeyT>^ QMap<KeyT, ValueT>::keys()
{
    return gcnew QList<KeyT>( _keyCompare, ref().keys() );
}

generic <typename KeyT, typename ValueT>
QList<KeyT>^ QMap<KeyT, ValueT>::keys(ValueT val)
{
    return gcnew QList<KeyT>( _keyCompare, ref().keys(NativeCollectionItem(_valCompare, val)) );
}

generic <typename KeyT, typename ValueT>
QList<ValueT>^ QMap<KeyT, ValueT>::values()
{
    return gcnew QList<ValueT>( _valCompare, ref().values() );
}

generic <typename KeyT, typename ValueT>
QList<ValueT>^ QMap<KeyT, ValueT>::values(KeyT key)
{
    return gcnew QList<ValueT>( _valCompare, ref().values(NativeCollectionItem(_keyCompare, key)) );
}

generic <typename KeyT, typename ValueT>
int QMap<KeyT, ValueT>::count(KeyT key)
{
    return ref().count(NativeCollectionItem(_keyCompare, key));
}

generic <typename KeyT, typename ValueT>
Collections::IEnumerator^ QMap<KeyT, ValueT>::EnumerableGetEnumerator()
{
    throw gcnew NotImplementedException();
}

generic <typename KeyT, typename ValueT>
IEnumerator<KeyValuePair<KeyT, ValueT> >^ QMap<KeyT, ValueT>::GetEnumerator()
{
    throw gcnew NotImplementedException();
}

generic <typename KeyT, typename ValueT>
int QMap<KeyT, ValueT>::Count::get()
{
    return Size;
}

generic <typename KeyT, typename ValueT>
bool QMap<KeyT, ValueT>::IsReadOnly::get()
{
    return false;
}

generic <typename KeyT, typename ValueT>
void QMap<KeyT, ValueT>::Add(KVP pair)
{
    throw gcnew NotImplementedException();
}

generic <typename KeyT, typename ValueT>
void QMap<KeyT, ValueT>::Clear()
{
    clear();
}

generic <typename KeyT, typename ValueT>
bool QMap<KeyT, ValueT>::Contains(KVP)
{
    throw gcnew NotImplementedException();
}

generic <typename KeyT, typename ValueT>
void QMap<KeyT, ValueT>::CopyTo(array<KVP>^, int)
{
    throw gcnew NotImplementedException();
}

generic <typename KeyT, typename ValueT>
bool QMap<KeyT, ValueT>::Remove(KVP)
{
    throw gcnew NotImplementedException();
}

generic <typename KeyT, typename ValueT>
ValueT QMap<KeyT, ValueT>::default::get(KeyT key)
{
    Object^ val = ref()[NativeCollectionItem(_keyCompare, key)].Item();
    return (ValueT)val;
}

generic <typename KeyT, typename ValueT>
void QMap<KeyT, ValueT>::default::set(KeyT key, ValueT val)
{
    ref()[NativeCollectionItem(_keyCompare, key)] = NativeCollectionItem(_valCompare, val);
}

generic <typename KeyT, typename ValueT>
ICollection<KeyT>^ QMap<KeyT, ValueT>::Keys::get()
{
    throw gcnew NotImplementedException();
}

generic <typename KeyT, typename ValueT>
ICollection<ValueT>^ QMap<KeyT, ValueT>::Values::get()
{
    throw gcnew NotImplementedException();
}

generic <typename KeyT, typename ValueT>
bool QMap<KeyT, ValueT>::ContainsKey(KeyT key)
{
    return contains(key);
}

generic <typename KeyT, typename ValueT>
void QMap<KeyT, ValueT>::Add(KeyT key, ValueT val)
{
    ref()[NativeCollectionItem(_keyCompare, key)] = NativeCollectionItem(_valCompare, val);
}

generic <typename KeyT, typename ValueT>
bool QMap<KeyT, ValueT>::Remove(KeyT key)
{
    return (remove(key) >= 0);
}

generic <typename KeyT, typename ValueT>
bool QMap<KeyT, ValueT>::TryGetValue(KeyT key, ValueT% val)
{
    throw gcnew NotImplementedException();
}

NAMESPACE_END;
