/****************************************************************************
** Meta object code from reading C++ file 'idom_client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../test/idom_client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'idom_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_iDom_client_t {
    QByteArrayData data[8];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iDom_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iDom_client_t qt_meta_stringdata_iDom_client = {
    {
QT_MOC_LITERAL(0, 0, 11), // "iDom_client"
QT_MOC_LITERAL(1, 12, 27), // "on_progressBar_valueChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 5), // "value"
QT_MOC_LITERAL(4, 47, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 69, 22), // "on_pushButton_released"
QT_MOC_LITERAL(6, 92, 18), // "on_swiatlo_clicked"
QT_MOC_LITERAL(7, 111, 27) // "on_lineEdit_editingFinished"

    },
    "iDom_client\0on_progressBar_valueChanged\0"
    "\0value\0on_pushButton_clicked\0"
    "on_pushButton_released\0on_swiatlo_clicked\0"
    "on_lineEdit_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iDom_client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void iDom_client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        iDom_client *_t = static_cast<iDom_client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_progressBar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_released(); break;
        case 3: _t->on_swiatlo_clicked(); break;
        case 4: _t->on_lineEdit_editingFinished(); break;
        default: ;
        }
    }
}

const QMetaObject iDom_client::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_iDom_client.data,
      qt_meta_data_iDom_client,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *iDom_client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iDom_client::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_iDom_client.stringdata0))
        return static_cast<void*>(const_cast< iDom_client*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int iDom_client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
