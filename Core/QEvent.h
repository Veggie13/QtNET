#pragma once

#pragma managed (push, off)
#include <QtCore/QEvent>
#pragma managed (pop)

NAMESPACE_BEGIN;

WRAPPER(QEvent)
{
public:
    enum class Type
    {
    };

    QEvent(LOCAL(QEvent)::Type);

    property bool Accepted { bool get(); void set(bool); }
    property bool Spontaneous { bool get(); }
    property Type type { Type get(); }

    void accept();
    void ignore();

internal:
    QEvent(NATIVE(QEvent)*);
    QEvent(NATIVE(QEvent)&);
};

NAMESPACE_END;
