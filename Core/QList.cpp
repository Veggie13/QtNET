#include "QtNET.h"

#include "QList.h"

using namespace helper;
using namespace System;
using namespace System::Collections::Generic;


NAMESPACE_BEGIN;

generic <typename T>
QList<T>::QList()
    :   NativeWrapper()
    ,   _compare( NativeCollectionItem::Comparison(T::typeid) )
{
}

generic <typename T>
QList<T>::QList(IObjectComparison^ compare, const NativeT& other)
    :   NativeWrapper(other)
    ,   _compare(compare)
{
}

generic <typename T>
QList<T>::QList(EnumerableG^)
    :   NativeWrapper()
    ,   _compare( NativeCollectionItem::Comparison(T::typeid) )
{
    throw gcnew NotImplementedException();
}

generic <typename T>
QList<T>::QList(CurrT^ other)
    :   NativeWrapper(other->ref())
    ,   _compare(other->_compare)
{
}

generic <typename T>
int QList<T>::Size::get()
{
    return ref().size();
}

generic <typename T>
bool QList<T>::IsDetached::get()
{
    return ref().isDetached();
}

generic <typename T>
void QList<T>::Sharable::set(bool val)
{
    ref().setSharable(val);
}

generic <typename T>
bool QList<T>::IsEmpty::get()
{
    return ref().isEmpty();
}

generic <typename T>
int QList<T>::Length::get()
{
    return ref().length();
}

generic <typename T>
T QList<T>::First::get()
{
    return (T)ref().first().Item();
}

generic <typename T>
T QList<T>::Last::get()
{
    return (T)ref().last().Item();
}

generic <typename T>
void QList<T>::detach()
{
    ref().detach();
}

generic <typename T>
void QList<T>::detachShared()
{
    ref().detachShared();
}

generic <typename T>
void QList<T>::clear()
{
    ref().clear();
}

generic <typename T>
void QList<T>::reserve(int size)
{
    ref().reserve(size);
}

generic <typename T>
void QList<T>::append(T item)
{
    ref().append(NativeCollectionItem(_compare, item));
}

generic <typename T>
void QList<T>::append(CurrT^ other)
{
    ref().append(other->ref());
}

generic <typename T>
void QList<T>::prepend(T item)
{
    ref().prepend(NativeCollectionItem(_compare, item));
}

generic <typename T>
void QList<T>::insert(int i, T item)
{
    ref().insert(i, NativeCollectionItem(_compare, item));
}

generic <typename T>
void QList<T>::replace(int i, T item)
{
    ref().replace(i, NativeCollectionItem(_compare, item));
}

generic <typename T>
void QList<T>::removeAt(int i)
{
    ref().removeAt(i);
}

generic <typename T>
void QList<T>::removeAll(T item)
{
    ref().removeAll(NativeCollectionItem(_compare, item));
}

generic <typename T>
bool QList<T>::removeOne(T item)
{
    return ref().removeOne(NativeCollectionItem(_compare, item));
}

generic <typename T>
T QList<T>::takeAt(int i)
{
    return (T)ref().takeAt(i).Item();
}

generic <typename T>
T QList<T>::takeFirst()
{
    return (T)ref().takeFirst().Item();
}

generic <typename T>
T QList<T>::takeLast()
{
    return (T)ref().takeLast().Item();
}

generic <typename T>
void QList<T>::move(int from, int to)
{
    ref().move(from, to);
}

generic <typename T>
void QList<T>::swap(int i, int j)
{
    ref().swap(i, j);
}

generic <typename T>
int QList<T>::indexOf(T item)
{
    return ref().indexOf(NativeCollectionItem(_compare, item));
}

generic <typename T>
int QList<T>::indexOf(T item, int from)
{
    return ref().indexOf(NativeCollectionItem(_compare, item), from);
}

generic <typename T>
int QList<T>::lastIndexOf(T item)
{
    return ref().lastIndexOf(NativeCollectionItem(_compare, item));
}

generic <typename T>
int QList<T>::lastIndexOf(T item, int from)
{
    return ref().lastIndexOf(NativeCollectionItem(_compare, item), from);
}

generic <typename T>
bool QList<T>::contains(T item)
{
    return ref().contains(NativeCollectionItem(_compare, item));
}

generic <typename T>
int QList<T>::count(T item)
{
    return ref().count(NativeCollectionItem(_compare, item));
}

generic <typename T>
int QList<T>::count()
{
    return ref().count();
}

generic <typename T>
void QList<T>::removeFirst()
{
    ref().removeFirst();
}

generic <typename T>
void QList<T>::removeLast()
{
    ref().removeLast();
}

generic <typename T>
bool QList<T>::startsWith(T item)
{
    return ref().startsWith(NativeCollectionItem(_compare, item));
}

generic <typename T>
bool QList<T>::endsWith(T item)
{
    return ref().endsWith(NativeCollectionItem(_compare, item));
}

generic <typename T>
QList<T>^ QList<T>::mid(int pos)
{
    return gcnew CurrT( _compare, ref().mid(pos) );
}

generic <typename T>
QList<T>^ QList<T>::mid(int pos, int length)
{
    return gcnew CurrT( _compare, ref().mid(pos, length) );
}

generic <typename T>
T QList<T>::value(int i)
{
    return (T)ref().value(i).Item();
}

generic <typename T>
T QList<T>::value(int i, T defaultValue)
{
    return (T)ref().value(i, NativeCollectionItem(_compare, defaultValue)).Item();
}

generic <typename T>
Collections::IEnumerator^ QList<T>::EnumerableGetEnumerator()
{
    throw gcnew NotImplementedException();
}

generic <typename T>
IEnumerator<T>^ QList<T>::GetEnumerator()
{
    throw gcnew NotImplementedException();
}

generic <typename T>
int QList<T>::Count::get()
{
    return ref().count();
}

generic <typename T>
bool QList<T>::IsReadOnly::get()
{
    return false;
}

generic <typename T>
void QList<T>::Add(T item)
{
    append(item);
}

generic <typename T>
void QList<T>::Clear()
{
    clear();
}

generic <typename T>
bool QList<T>::Contains(T item)
{
    return contains(item);
}

generic <typename T>
void QList<T>::CopyTo(array<T>^, int)
{
    throw gcnew NotImplementedException();
}

generic <typename T>
bool QList<T>::Remove(T item)
{
    return removeOne(item);
}

generic <typename T>
T QList<T>::default::get(int i)
{
    return (T)ref()[i];
}

generic <typename T>
void QList<T>::default::set(int i, T item)
{
    ref()[i] = NativeCollectionItem(_compare, item);
}

generic <typename T>
int QList<T>::IndexOf(T item)
{
    return indexOf(item);
}

generic <typename T>
void QList<T>::Insert(int i, T item)
{
    insert(i, item);
}

generic <typename T>
void QList<T>::RemoveAt(int i)
{
    removeAt(i);
}

NAMESPACE_END;
