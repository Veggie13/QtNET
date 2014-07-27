#include "QtNET.h"

#include "QWidget.h"

NAMESPACE_BEGIN;

QWidget::QWidget()
    :   NativeInheritWrapper()
{
}

QWidget::QWidget(QWidget^ parent)
    :   NativeInheritWrapper(init<NATIVE(QWidget)>(parent))
{
}

QWidget::QWidget(QWidget^ parent, WindowType f)
    :   NativeInheritWrapper(init<NATIVE(QWidget)>(parent, f))
{
}

QWidget::QWidget(NATIVE(QWidget)* native)
    :   NativeInheritWrapper(native)
{
}

QWidget::QWidget(NATIVE(QWidget)& native)
    :   NativeInheritWrapper(native)
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
