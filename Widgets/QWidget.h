#pragma once

#pragma managed (push, off)
#include <QtWidgets/QWidget>
#pragma managed (pop)
#include "WindowType.h"

NAMESPACE_BEGIN;

    INHERIT_EXT_WRAPPER(QWidget, Core, QObject)
    {
    internal:
        QWidget(NATIVE(QWidget)*);
        QWidget(NATIVE(QWidget)&);

    public:
        QWidget();
        QWidget(QWidget^);
        QWidget(QWidget^, QtNET::WindowType);

        property QN_STR^ WindowTitle { QN_STR^ get(); void set(QN_STR^); }

        void show();

    protected:
        template <class OutT>
        static OutT* init(QWidget^ parent)
        {
            return new OutT((parent == nullptr) ? NULL : &parent->ref());
        }
        template <class OutT>
        static OutT* init(QWidget^ parent, QtNET::WindowType f)
        {
            return new OutT((parent == nullptr) ? NULL : &parent->ref(), (Qt::WindowType)f);
        }

    };

NAMESPACE_END;
