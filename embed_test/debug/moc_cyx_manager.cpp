/****************************************************************************
** Meta object code from reading C++ file 'cyx_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cyx_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cyx_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Cyx_Manager_t {
    QByteArrayData data[9];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cyx_Manager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cyx_Manager_t qt_meta_stringdata_Cyx_Manager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Cyx_Manager"
QT_MOC_LITERAL(1, 12, 8), // "got_path"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "on_show"
QT_MOC_LITERAL(4, 30, 7), // "on_exit"
QT_MOC_LITERAL(5, 38, 17), // "on_select_clicked"
QT_MOC_LITERAL(6, 56, 12), // "on_activated"
QT_MOC_LITERAL(7, 69, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(8, 103, 6) // "reason"

    },
    "Cyx_Manager\0got_path\0\0on_show\0on_exit\0"
    "on_select_clicked\0on_activated\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cyx_Manager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   42,    2, 0x0a /* Public */,
       4,    0,   43,    2, 0x0a /* Public */,
       5,    0,   44,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void Cyx_Manager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cyx_Manager *_t = static_cast<Cyx_Manager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->got_path((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_show(); break;
        case 2: _t->on_exit(); break;
        case 3: _t->on_select_clicked(); break;
        case 4: _t->on_activated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Cyx_Manager::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cyx_Manager::got_path)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Cyx_Manager::staticMetaObject = {
    { &Cyx_Base_Window::staticMetaObject, qt_meta_stringdata_Cyx_Manager.data,
      qt_meta_data_Cyx_Manager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Cyx_Manager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cyx_Manager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Cyx_Manager.stringdata0))
        return static_cast<void*>(const_cast< Cyx_Manager*>(this));
    return Cyx_Base_Window::qt_metacast(_clname);
}

int Cyx_Manager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Cyx_Base_Window::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Cyx_Manager::got_path(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
