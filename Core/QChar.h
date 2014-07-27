#pragma once

#pragma managed (push, off)
#include <QtCore/QChar>
#pragma managed (pop)


NAMESPACE_BEGIN;

    WRAPPER(QChar)
    {
    public:
        QChar();
        QChar(wchar_t);

    internal:
        QChar(const NATIVE(QChar)&);
    };

NAMESPACE_END;
