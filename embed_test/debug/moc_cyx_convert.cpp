/****************************************************************************
** Meta object code from reading C++ file 'cyx_convert.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cyx_convert.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cyx_convert.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Cyx_Convert_t {
    QByteArrayData data[4];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cyx_Convert_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cyx_Convert_t qt_meta_stringdata_Cyx_Convert = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Cyx_Convert"
QT_MOC_LITERAL(1, 12, 9), // "Converted"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14) // "on_CheckSource"

    },
    "Cyx_Convert\0Converted\0\0on_CheckSource"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cyx_Convert[] = {

 // content:
       7,       // revision
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

 // slots: name, argc, parameters, tag, flags
       3,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void Cyx_Convert::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cyx_Convert *_t = static_cast<Cyx_Convert *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Converted((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_CheckSource((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Cyx_Convert::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cyx_Convert::Converted)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Cyx_Convert::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Cyx_Convert.data,
      qt_meta_data_Cyx_Convert,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Cyx_Convert::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cyx_Convert::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Cyx_Convert.stringdata0))
        return static_cast<void*>(const_cast< Cyx_Convert*>(this));
    return QObject::qt_metacast(_clname);
}

int Cyx_Convert::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Cyx_Convert::Converted(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
