#include "QtNET.h"

#include "QString.h"

using namespace System;


NAMESPACE_BEGIN;

QString::QString(const NATIVE(QString)& other)
    :   NativeWrapper(other)
{
}

QString::QString()
    :   NativeWrapper()
{
}

QString::QString(String^ str)
    :   NativeWrapper(init(str))
{
}

String^ QString::ToString()
{
    return (String^)this;
}

int QString::GetHashCode()
{
    return ToString()->GetHashCode();
}

bool QString::Equals(Object^ o)
{
    return Equals(dynamic_cast<QString^>(o));
}

int QString::CompareTo(QString^ other)
{
    if (ref() < other->ref())
    {
        return -1;
    }
    if (ref() > other->ref())
    {
        return 1;
    }
    return 0;
}

bool QString::Equals(QString^ other)
{
    if (other == nullptr)
    {
        return false;
    }
    return (ref() == other->ref());
}

NATIVE(QString)* QString::init(String^ str)
{
    pin_ptr<const wchar_t> p = PtrToStringChars(str);
    const wchar_t* buf = p;
    return new NATIVE(QString)(NATIVE(QString)::fromUtf16((const ushort*)buf));
}

QString::operator QString^ (String^ str)
{
    return gcnew QString(str);
}

QString::operator String^ (QString^ qstr)
{
    return gcnew String((const wchar_t*)qstr->ref().utf16());
}

NAMESPACE_END;
