#pragma once

#pragma managed (push, off)
#include <QtCore/QObject>
#pragma managed (pop)

namespace helper { class QObject_internal; }

NAMESPACE_BEGIN;
ref class QEvent;
ref class QString;

WRAPPER(QObject)
{
public:
    QObject();
    QObject(QObject^);

    delegate void DestroyEvent(QObject^);
    event DestroyEvent^ Destroyed;
    delegate void ObjectNameChangeEvent(LOCAL(QString)^);
    event ObjectNameChangeEvent^ ObjectNameChanged;

    property bool SignalsBlocked { bool get(); void set(bool); }
    property bool IsWidgetType { bool get(); }
    property bool IsWindowType { bool get(); }
    property QObject^ Parent { QObject^ get(); void set(QObject^); }
    property LOCAL(QString)^ ObjectName { LOCAL(QString)^ get(); void set(LOCAL(QString)^); }

    void deleteLater();
    void dumpObjectInfo();
    void dumpObjectTree();
    virtual bool Event(QEvent^);
    virtual bool eventFilter(QObject^, QEvent^);
    void installEventFilter(QObject^);
    void killTimer(int);
    void removeEventFilter(QObject^);

protected:
    static ::helper::QObject_internal* initHelper(QObject^);
    static ::helper::QObject_internal* initHelper(QObject^, NATIVE(QObject)* parent);

    ::helper::QObject_internal& ref2();
    ::helper::QObject_internal* ptr2();

internal:
    QObject(NATIVE(QObject)*);
    QObject(NATIVE(QObject)&);

    void emitDestroyed(QObject^);
    void emitObjectNameChanged(LOCAL(QString)^);
};

NAMESPACE_END;
