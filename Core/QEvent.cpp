#include "QtNET.h"

#include "QEvent.h"

using namespace System;


NAMESPACE_BEGIN;

QEvent::QEvent(LOCAL(QEvent)::Type type)
    :   NativeWrapper((NATIVE(QEvent::Type))type)
{
}

QEvent::QEvent(NATIVE(QEvent)* obj)
    :   NativeWrapper(obj)
{
}

QEvent::QEvent(NATIVE(QEvent)& obj)
    :   NativeWrapper(obj)
{
}

bool QEvent::Accepted::get()
{
    return ref().isAccepted();
}

void QEvent::Accepted::set(bool val)
{
    ref().setAccepted(val);
}

bool QEvent::Spontaneous::get()
{
    return ref().spontaneous();
}

QEvent::Type QEvent::type::get()
{
    return (QEvent::Type)ref().type();
}

void QEvent::accept()
{
    ref().accept();
}

void QEvent::ignore()
{
    ref().ignore();
}

NAMESPACE_END;
