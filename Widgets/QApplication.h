#pragma once

#pragma managed (push, off)
#include <QtWidgets/QApplication>
#pragma managed (pop)

DISABLE_DEFAULT(QApplication)

NAMESPACE_BEGIN;

    WRAPPER(QApplication)
	{
    public:
        QApplication(array<System::String^>^ args);

        int exec();

    protected:
        static NATIVE(QApplication)* init(array<System::String^>^ args);
	};

NAMESPACE_END;
