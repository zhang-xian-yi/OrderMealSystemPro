/****************************************************************************
** Meta object code from reading C++ file 'sysservicecontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/service/sysservicecontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sysservicecontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SysServiceControl_t {
    QByteArrayData data[9];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SysServiceControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SysServiceControl_t qt_meta_stringdata_SysServiceControl = {
    {
QT_MOC_LITERAL(0, 0, 17), // "SysServiceControl"
QT_MOC_LITERAL(1, 18, 17), // "signal_login_info"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 3), // "cmd"
QT_MOC_LITERAL(4, 41, 14), // "signal_stopApp"
QT_MOC_LITERAL(5, 56, 4), // "type"
QT_MOC_LITERAL(6, 61, 14), // "slot_dealLogin"
QT_MOC_LITERAL(7, 76, 4), // "name"
QT_MOC_LITERAL(8, 81, 6) // "passwd"

    },
    "SysServiceControl\0signal_login_info\0"
    "\0cmd\0signal_stopApp\0type\0slot_dealLogin\0"
    "name\0passwd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SysServiceControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,

       0        // eod
};

void SysServiceControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SysServiceControl *_t = static_cast<SysServiceControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_login_info((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->signal_stopApp((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->slot_dealLogin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SysServiceControl::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SysServiceControl::signal_login_info)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SysServiceControl::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SysServiceControl::signal_stopApp)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SysServiceControl::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_SysServiceControl.data,
    qt_meta_data_SysServiceControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SysServiceControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SysServiceControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SysServiceControl.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SysServiceControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SysServiceControl::signal_login_info(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SysServiceControl::signal_stopApp(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
