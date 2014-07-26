#pragma once

#pragma managed (push, off)
#include <QtWidgets/QMainWindow>
#pragma managed (pop)
#include "QWidget.h"

NAMESPACE_BEGIN;

    INHERIT_WRAPPER(QMainWindow, QWidget)
    {
    public:
        QMainWindow();
        QMainWindow(QWidget^ parent);
        QMainWindow(QWidget^ parent, QtNET::WindowType f);
    };

NAMESPACE_END;
