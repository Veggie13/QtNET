#pragma once

#pragma managed (push, off)
#include <QtCore/QString>
#pragma managed (pop)

NAMESPACE_BEGIN;

    WRAPPER(QString)
        , System::IComparable<LOCAL(QString)^>
        , System::IEquatable<LOCAL(QString)^>
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
        virtual bool Equals(System::Object^) override;

#pragma region IComparable<>
        virtual int CompareTo(QString^);
#pragma endregion

#pragma region IEquatable<>
        virtual bool Equals(QString^);
#pragma endregion

    protected:
        static NATIVE(QString)* init(System::String^);
    };

NAMESPACE_END;
