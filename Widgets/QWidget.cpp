#include "QtNET.h"

#include "QWidget.h"


NAMESPACE_BEGIN;

QWidget::QWidget()
    :   NativeInheritWrapper()
{
}

QWidget::QWidget(QWidget^ parent)
    :   NativeInheritWrapper(init<NATIVE(QWidget)>(parent), true)
{
}

QWidget::QWidget(QWidget^ parent, WindowType f)
    :   NativeInheritWrapper(init<NATIVE(QWidget)>(parent, f), true)
{
}

QWidget::QWidget(NATIVE(QWidget)* native, bool destroy)
    :   NativeInheritWrapper(native, destroy)
{
}

QN_STR^ QWidget::WindowTitle::get()
{
    return gcnew QN_STR(ref().windowTitle());
}

void QWidget::WindowTitle::set(QN_STR^ val)
{
    ref().setWindowTitle(val->ref());
}

void QWidget::show()
{
    ref().show();
}

NAMESPACE_END;
