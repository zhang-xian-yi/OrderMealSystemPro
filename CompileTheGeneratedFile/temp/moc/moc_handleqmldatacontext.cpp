/****************************************************************************
** Meta object code from reading C++ file 'handleqmldatacontext.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/service/qml_service/qml_connect/qml_data_handle/handleqmldatacontext.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handleqmldatacontext.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HandleQMLDataContext_t {
    QByteArrayData data[9];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HandleQMLDataContext_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HandleQMLDataContext_t qt_meta_stringdata_HandleQMLDataContext = {
    {
QT_MOC_LITERAL(0, 0, 20), // "HandleQMLDataContext"
QT_MOC_LITERAL(1, 21, 19), // "slotMqttDoConnected"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 26), // "slotMqttBrokerDisconnected"
QT_MOC_LITERAL(4, 69, 19), // "slotMqttStateChange"
QT_MOC_LITERAL(5, 89, 22), // "slotMqttMessageRecvied"
QT_MOC_LITERAL(6, 112, 7), // "message"
QT_MOC_LITERAL(7, 120, 14), // "QMqttTopicName"
QT_MOC_LITERAL(8, 135, 5) // "topic"

    },
    "HandleQMLDataContext\0slotMqttDoConnected\0"
    "\0slotMqttBrokerDisconnected\0"
    "slotMqttStateChange\0slotMqttMessageRecvied\0"
    "message\0QMqttTopicName\0topic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HandleQMLDataContext[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    2,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 7,    6,    8,

       0        // eod
};

void HandleQMLDataContext::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HandleQMLDataContext *_t = static_cast<HandleQMLDataContext *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotMqttDoConnected(); break;
        case 1: _t->slotMqttBrokerDisconnected(); break;
        case 2: _t->slotMqttStateChange(); break;
        case 3: _t->slotMqttMessageRecvied((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QMqttTopicName(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttTopicName >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HandleQMLDataContext::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HandleQMLDataContext.data,
    qt_meta_data_HandleQMLDataContext,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HandleQMLDataContext::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HandleQMLDataContext::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HandleQMLDataContext.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HandleQMLDataContext::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
