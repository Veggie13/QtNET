#include "QtNET.h"

#include "QMainWindow.h"

using namespace System;


NAMESPACE_BEGIN;

QMainWindow::QMainWindow()
    :   NativeInheritWrapper()
{
}

QMainWindow::QMainWindow(QWidget^ parent)
    :   NativeInheritWrapper(init<NATIVE(QMainWindow)>(parent))
{
}

QMainWindow::QMainWindow(QWidget^ parent, WindowType f)
    :   NativeInheritWrapper(init<NATIVE(QMainWindow)>(parent, f))
{
}

NAMESPACE_END;
