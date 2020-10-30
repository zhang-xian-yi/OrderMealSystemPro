/****************************************************************************
** Meta object code from reading C++ file 'qmlconnecter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/service/qml_service/qml_connect/qmlconnecter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmlconnecter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QMLCmdConnecter_t {
    QByteArrayData data[6];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMLCmdConnecter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMLCmdConnecter_t qt_meta_stringdata_QMLCmdConnecter = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QMLCmdConnecter"
QT_MOC_LITERAL(1, 16, 10), // "signal_cmd"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "cmd"
QT_MOC_LITERAL(4, 32, 9), // "handleCmd"
QT_MOC_LITERAL(5, 42, 7) // "content"

    },
    "QMLCmdConnecter\0signal_cmd\0\0cmd\0"
    "handleCmd\0content"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMLCmdConnecter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    2,   27,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    5,

       0        // eod
};

void QMLCmdConnecter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QMLCmdConnecter *_t = static_cast<QMLCmdConnecter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_cmd((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->handleCmd((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QMLCmdConnecter::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLCmdConnecter::signal_cmd)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QMLCmdConnecter::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_QMLCmdConnecter.data,
    qt_meta_data_QMLCmdConnecter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QMLCmdConnecter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMLCmdConnecter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QMLCmdConnecter.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QMLCmdConnecter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QMLCmdConnecter::signal_cmd(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
