#pragma once

#pragma managed (push, off)
#include <QtCore/QList>
#pragma managed (pop)
#include "NativeCollectionItem.h"


NAMESPACE_BEGIN;

generic <typename T>
public ref class QList
    :   public NativeWrapper< NATIVE(QList<::helper::NativeCollectionItem>) >
    ,   public System::Collections::Generic::IList<T>
{
    typedef LOCAL(QList<T>) CurrT;
    typedef System::Collections::IEnumerator EnumeratorI;
    typedef System::Collections::IEnumerable EnumerableI;
    typedef System::Collections::Generic::IEnumerable<T> EnumerableG;
    typedef System::Collections::Generic::IEnumerator<T> EnumeratorG;

    ::helper::IObjectComparison^ _compare;

public:
    QList();
    QList(EnumerableG^);
    QList(CurrT^);

    property int Size { int get(); }
    property bool IsDetached { bool get(); }
    property bool Sharable { void set(bool); }
    property bool IsEmpty { bool get(); }
    property int Length { int get(); }
    property T First { T get(); }
    property T Last { T get(); }

    void detach();

    void detachShared();

    void clear();

    void reserve(int);
    void append(T);
    void append(CurrT^);
    void prepend(T);
    void insert(int, T);
    void replace(int, T);
    void removeAt(int);
    void removeAll(T);
    bool removeOne(T);
    T takeAt(int);
    T takeFirst();
    T takeLast();
    void move(int, int);
    void swap(int, int);
    int indexOf(T);
    int indexOf(T, int);
    int lastIndexOf(T);
    int lastIndexOf(T, int);
    bool contains(T);
    int count(T);

    int count();
    void removeFirst();
    void removeLast();
    bool startsWith(T);
    bool endsWith(T);
    CurrT^ mid(int);
    CurrT^ mid(int, int);

    T value(int);
    T value(int, T);

#pragma region IList<>
#pragma region ICollection<>
#pragma region IEnumerable<>
#pragma region IEnumerable
    virtual EnumeratorI^ EnumerableGetEnumerator() = EnumerableI::GetEnumerator;
#pragma endregion

    virtual EnumeratorG^ GetEnumerator();
#pragma endregion

    property int Count { virtual int get(); }
    property bool IsReadOnly { virtual bool get(); }

    virtual void Add(T);
    virtual void Clear();
    virtual bool Contains(T);
    virtual void CopyTo(array<T>^, int);
    virtual bool Remove(T);
#pragma endregion

    property T default[int]
    {
        virtual T get(int);
        virtual void set(int, T);
    }

    virtual int IndexOf(T);
    virtual void Insert(int, T);
    virtual void RemoveAt(int);
#pragma endregion

internal:
    QList(::helper::IObjectComparison^, const NativeT&);

};

NAMESPACE_END;
