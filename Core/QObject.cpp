#include "QtNET.h"

#include "QObject.h"
#include "QString.h"
#include "QEvent.h"
#include "QObject_internal.qoh"
#include "generated/QObject_internal.moc.cpp"

using namespace System;

NAMESPACE_BEGIN;
ref class QObject_basic : QObject
{
public:
    QObject_basic(NATIVE(QObject)& obj) : QObject(obj) {}

    virtual bool Event(LOCAL(QEvent)^ evt) override
    {
        return ref().event(evt->ptr());
    }

    virtual bool eventFilter(LOCAL(QObject)^ obj, LOCAL(QEvent)^ evt) override
    {
        return ref().eventFilter(obj->ptr(), evt->ptr());
    }
};
NAMESPACE_END;

namespace helper
{

QObject_internal::QObject_internal(gcroot<LOCAL(QObject)^> wrapper)
    :   QObject(NULL)
    ,   _wrapper(wrapper)
{
    connectToWrapper();
}

QObject_internal::QObject_internal(gcroot<LOCAL(QObject)^> wrapper, QObject* parent)
    :   QObject(parent)
    ,   _wrapper(wrapper)
{
    connectToWrapper();
}

void QObject_internal::connectToWrapper()
{
    connect(this, SIGNAL( destroyed(QObject*)   ),
            this, SLOT  ( onDestroyed(QObject*) ));
    connect(this, SIGNAL( objectNameChanged(const QString&)     ),
            this, SLOT  ( onObjectNameChanged(const QString&)   ));
}

bool QObject_internal::event(NATIVE(QEvent)* evt)
{
    return _wrapper->Event(gcnew LOCAL(QEvent)(*evt));
}

bool QObject_internal::base_event(NATIVE(QEvent)* evt)
{
    return QObject::event(evt);
}

bool QObject_internal::eventFilter(QObject* obj, NATIVE(QEvent)* evt)
{
    return _wrapper->eventFilter(gcnew LOCAL(QObject_basic)(*obj), gcnew LOCAL(QEvent)(*evt));
}

bool QObject_internal::base_eventFilter(QObject* obj, NATIVE(QEvent)* evt)
{
    return QObject::eventFilter(obj, evt);
}

void QObject_internal::onDestroyed(NATIVE(QObject)* o)
{
    _wrapper->emitDestroyed((o == NULL) ? nullptr : gcnew LOCAL(QObject_basic)(*o));
}

void QObject_internal::onObjectNameChanged(const NATIVE(QString)& name)
{
    _wrapper->emitObjectNameChanged(gcnew LOCAL(QString)(name));
}

}

NAMESPACE_BEGIN;

QObject::QObject()
    :   NativeWrapper(initHelper(this, NULL))
{
}

QObject::QObject(QObject^ parent)
    :   NativeWrapper(initHelper(this, parent->ptr()))
{
}

QObject::QObject(NATIVE(QObject)* o)
    :   NativeWrapper(o)
{
}

QObject::QObject(NATIVE(QObject)& o)
    :   NativeWrapper(o)
{
}

::helper::QObject_internal* QObject::initHelper(LOCAL(QObject)^ wrapper)
{
    return new ::helper::QObject_internal(wrapper);
}

::helper::QObject_internal* QObject::initHelper(LOCAL(QObject)^ wrapper, NATIVE(QObject*) parent)
{
    return new ::helper::QObject_internal(wrapper, parent);
}

::helper::QObject_internal& QObject::ref2()
{
    return dynamic_cast<::helper::QObject_internal&>(ref());
}

::helper::QObject_internal* QObject::ptr2()
{
    return dynamic_cast<::helper::QObject_internal*>(ptr());
}

bool QObject::SignalsBlocked::get()
{
    return ref().signalsBlocked();
}

void QObject::SignalsBlocked::set(bool val)
{
    ref().blockSignals(val);
}

bool QObject::IsWidgetType::get()
{
    return ref().isWidgetType();
}

bool QObject::IsWindowType::get()
{
    return ref().isWindowType();
}

QObject^ QObject::Parent::get()
{
    return gcnew QObject_basic(*ref().parent());
}

void QObject::Parent::set(QObject^ val)
{
    ref().setParent(val->ptr());
}

QString^ QObject::ObjectName::get()
{
    return gcnew QString(ref().objectName());
}

void QObject::ObjectName::set(QString^ val)
{
    ref().setObjectName(val->ref());
}

void QObject::deleteLater()
{
    ref().deleteLater();
}

void QObject::dumpObjectInfo()
{
    ref().dumpObjectInfo();
}

void QObject::dumpObjectTree()
{
    ref().dumpObjectTree();
}

bool QObject::Event(QEvent^ evt)
{
    return ref2().base_event(evt->ptr());
}

bool QObject::eventFilter(QObject^ watched, QEvent^ evt)
{
    return ref2().base_eventFilter(watched->ptr(), evt->ptr());
}

void QObject::installEventFilter(QObject^ filter)
{
    ref().installEventFilter(filter->ptr());
}

void QObject::killTimer(int id)
{
    ref().killTimer(id);
}

void QObject::removeEventFilter(QObject^ obj)
{
    ref().removeEventFilter(obj->ptr());
}

void QObject::emitDestroyed(QObject^ obj)
{
    Destroyed(obj);
}

void QObject::emitObjectNameChanged(QString^ objectName)
{
    ObjectNameChanged(objectName);
}

NAMESPACE_END;
