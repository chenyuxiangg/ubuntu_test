/****************************************************************************
** Meta object code from reading C++ file 'cyx_file_check.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cyx_file_check.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cyx_file_check.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Cyx_File_Check_t {
    QByteArrayData data[9];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cyx_File_Check_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cyx_File_Check_t qt_meta_stringdata_Cyx_File_Check = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Cyx_File_Check"
QT_MOC_LITERAL(1, 15, 7), // "gotPath"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 21), // "on_select_btn_clicked"
QT_MOC_LITERAL(4, 46, 10), // "on_display"
QT_MOC_LITERAL(5, 57, 14), // "on_gotProgress"
QT_MOC_LITERAL(6, 72, 3), // "cur"
QT_MOC_LITERAL(7, 76, 5), // "total"
QT_MOC_LITERAL(8, 82, 11) // "on_addItems"

    },
    "Cyx_File_Check\0gotPath\0\0on_select_btn_clicked\0"
    "on_display\0on_gotProgress\0cur\0total\0"
    "on_addItems"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cyx_File_Check[] = {

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
       5,    2,   44,    2, 0x0a /* Public */,
       8,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void Cyx_File_Check::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cyx_File_Check *_t = static_cast<Cyx_File_Check *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gotPath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_select_btn_clicked(); break;
        case 2: _t->on_display(); break;
        case 3: _t->on_gotProgress((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 4: _t->on_addItems((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Cyx_File_Check::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cyx_File_Check::gotPath)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Cyx_File_Check::staticMetaObject = {
    { &Cyx_Base_Window::staticMetaObject, qt_meta_stringdata_Cyx_File_Check.data,
      qt_meta_data_Cyx_File_Check,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Cyx_File_Check::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cyx_File_Check::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Cyx_File_Check.stringdata0))
        return static_cast<void*>(const_cast< Cyx_File_Check*>(this));
    return Cyx_Base_Window::qt_metacast(_clname);
}

int Cyx_File_Check::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Cyx_File_Check::gotPath(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
