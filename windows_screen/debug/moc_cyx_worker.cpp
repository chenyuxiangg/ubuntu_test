/****************************************************************************
** Meta object code from reading C++ file 'cyx_worker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cyx_worker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cyx_worker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Cyx_Worker_t {
    QByteArrayData data[9];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cyx_Worker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cyx_Worker_t qt_meta_stringdata_Cyx_Worker = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Cyx_Worker"
QT_MOC_LITERAL(1, 11, 11), // "gotProgress"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "gotFiles"
QT_MOC_LITERAL(4, 33, 6), // "gotMd5"
QT_MOC_LITERAL(5, 40, 14), // "on_getFilesMd5"
QT_MOC_LITERAL(6, 55, 9), // "filenames"
QT_MOC_LITERAL(7, 65, 10), // "on_getFile"
QT_MOC_LITERAL(8, 76, 4) // "path"

    },
    "Cyx_Worker\0gotProgress\0\0gotFiles\0"
    "gotMd5\0on_getFilesMd5\0filenames\0"
    "on_getFile\0path"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cyx_Worker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       3,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   48,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    6,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void Cyx_Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cyx_Worker *_t = static_cast<Cyx_Worker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gotProgress((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 1: _t->gotFiles((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 2: _t->gotMd5(); break;
        case 3: _t->on_getFilesMd5((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 4: _t->on_getFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Cyx_Worker::*_t)(const int & , const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cyx_Worker::gotProgress)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Cyx_Worker::*_t)(const QStringList & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cyx_Worker::gotFiles)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Cyx_Worker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cyx_Worker::gotMd5)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Cyx_Worker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Cyx_Worker.data,
      qt_meta_data_Cyx_Worker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Cyx_Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cyx_Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Cyx_Worker.stringdata0))
        return static_cast<void*>(const_cast< Cyx_Worker*>(this));
    return QObject::qt_metacast(_clname);
}

int Cyx_Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Cyx_Worker::gotProgress(const int & _t1, const int & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Cyx_Worker::gotFiles(const QStringList & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Cyx_Worker::gotMd5()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
