#include "QtNET.h"

#include "QLabel.h"


NAMESPACE_BEGIN;
LOCALIZE(Core, QString);

QLabel::QLabel(QString^ text)
    :   NativeInheritWrapper(text->ref())
{
}

QLabel::QLabel(QString^ text, QWidget^ parent)
    :   NativeInheritWrapper(text->ref(), parent->ptr())
{
}

QLabel::QLabel(QString^ text, QWidget^ parent, WindowType f)
    :   NativeInheritWrapper(text->ref(), parent->ptr(), (NATIVE(Qt::WindowType))f)
{
}

QString^ QLabel::Text::get()
{
    return gcnew QString(ref().text());
}

void QLabel::Text::set(QString^ text)
{
    ref().setText(text->ref());
}

NAMESPACE_END;
