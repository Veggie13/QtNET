#pragma once

#pragma managed (push, off)
#include <QtWidgets/QWidget>
#pragma managed (pop)

QTNET_BEGIN;

    public enum class WindowType
    {
        Widget = NATIVE(Qt::Widget),
        Window = NATIVE(Qt::Window),
        Dialog = NATIVE(Qt::Dialog),
        Sheet = NATIVE(Qt::Sheet),
        Drawer = NATIVE(Qt::Drawer),
        Popup = NATIVE(Qt::Popup),
        Tool = NATIVE(Qt::Tool),
        ToolTip = NATIVE(Qt::ToolTip),
        SplashScreen = NATIVE(Qt::SplashScreen),
        Desktop = NATIVE(Qt::Desktop),
        SubWindow = NATIVE(Qt::SubWindow)
    };

QTNET_END;
