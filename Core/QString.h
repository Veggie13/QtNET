#pragma once

#pragma managed (push, off)
#include <QtCore/QString>
#pragma managed (pop)

NAMESPACE_BEGIN;

    WRAPPER(QString)
    {
    internal:
        QString(const NATIVE(QString)&);

    public:
        static operator System::String^ (QString^);
        static operator QString^ (System::String^);

        QString();
        QString(System::String^);

        virtual System::String^ ToString() override;
        virtual int GetHashCode() override;

    protected:
        static NATIVE(QString)* init(System::String^);
    };

NAMESPACE_END;
