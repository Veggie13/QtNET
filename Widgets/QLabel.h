#pragma once

#pragma managed (push, off)
#include <QtWidgets/QLabel>
#pragma managed (pop)
#include "QWidget.h"


NAMESPACE_BEGIN;

    INHERIT_WRAPPER(QLabel, QWidget)
    {
    public:
        QLabel(LIB_CLASS(Core, QString)^ text);
        QLabel(LIB_CLASS(Core, QString)^ text, QWidget^ parent);
        QLabel(LIB_CLASS(Core, QString)^ text, QWidget^ parent, QtNET::WindowType f);

        property LIB_CLASS(Core, QString)^ Text
        {
            LIB_CLASS(Core, QString)^ get();
            void set(LIB_CLASS(Core, QString)^);
        }
    };

NAMESPACE_END;
