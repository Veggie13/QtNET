#include "QtNET.h"

#include "QChar.h"

using namespace System;


NAMESPACE_BEGIN;

QChar::QChar(const NATIVE(QChar)& other)
    :   NativeWrapper(other)
{
}

QChar::QChar()
    :   NativeWrapper()
{
}

QChar::QChar(wchar_t c)
    :   NativeWrapper(c)
{
}

NAMESPACE_END;
