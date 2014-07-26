#pragma once

#pragma managed (push, off)
#include <QtCore/QChar>
#pragma managed (pop)


NAMESPACE_BEGIN;

    WRAPPER(QChar)
    {
    public:
        QChar(const NATIVE(QChar)&);
        QChar();
        QChar(wchar_t);
    };

NAMESPACE_END;
