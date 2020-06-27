/****************************************************************************
** Meta object code from reading C++ file 'loginui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ui/login/loginui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoginUi_t {
    QByteArrayData data[9];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginUi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginUi_t qt_meta_stringdata_LoginUi = {
    {
QT_MOC_LITERAL(0, 0, 7), // "LoginUi"
QT_MOC_LITERAL(1, 8, 5), // "close"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 11), // "slot_timer1"
QT_MOC_LITERAL(4, 27, 11), // "slot_timer2"
QT_MOC_LITERAL(5, 39, 14), // "slot_minWindow"
QT_MOC_LITERAL(6, 54, 16), // "slot_closeWindow"
QT_MOC_LITERAL(7, 71, 13), // "slot_trayIcon"
QT_MOC_LITERAL(8, 85, 16) // "slot_setLanguage"

    },
    "LoginUi\0close\0\0slot_timer1\0slot_timer2\0"
    "slot_minWindow\0slot_closeWindow\0"
    "slot_trayIcon\0slot_setLanguage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginUi[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LoginUi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginUi *_t = static_cast<LoginUi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->close(); break;
        case 1: _t->slot_timer1(); break;
        case 2: _t->slot_timer2(); break;
        case 3: _t->slot_minWindow(); break;
        case 4: _t->slot_closeWindow(); break;
        case 5: _t->slot_trayIcon(); break;
        case 6: _t->slot_setLanguage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LoginUi::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginUi::close)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject LoginUi::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_LoginUi.data,
    qt_meta_data_LoginUi,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LoginUi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginUi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoginUi.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LoginUi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void LoginUi::close()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
