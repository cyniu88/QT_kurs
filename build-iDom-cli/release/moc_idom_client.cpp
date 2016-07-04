/****************************************************************************
** Meta object code from reading C++ file 'idom_client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../iDom_Client/idom_client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'idom_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_iDom_Client_t {
    QByteArrayData data[18];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iDom_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iDom_Client_t qt_meta_stringdata_iDom_Client = {
    {
QT_MOC_LITERAL(0, 0, 11), // "iDom_Client"
QT_MOC_LITERAL(1, 12, 7), // "sendTCP"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "addres"
QT_MOC_LITERAL(4, 28, 11), // "std::string"
QT_MOC_LITERAL(5, 40, 1), // "s"
QT_MOC_LITERAL(6, 42, 22), // "on_EXITButton_released"
QT_MOC_LITERAL(7, 65, 22), // "on_label_linkActivated"
QT_MOC_LITERAL(8, 88, 4), // "link"
QT_MOC_LITERAL(9, 93, 28), // "on_disconnectButton_released"
QT_MOC_LITERAL(10, 122, 27), // "on_lineEdit_editingFinished"
QT_MOC_LITERAL(11, 150, 22), // "on_pushButton_released"
QT_MOC_LITERAL(12, 173, 22), // "on_playButton_released"
QT_MOC_LITERAL(13, 196, 12), // "zmienCounter"
QT_MOC_LITERAL(14, 209, 1), // "c"
QT_MOC_LITERAL(15, 211, 13), // "zmienCounter2"
QT_MOC_LITERAL(16, 225, 10), // "odb_answer"
QT_MOC_LITERAL(17, 236, 12) // "readProgress"

    },
    "iDom_Client\0sendTCP\0\0addres\0std::string\0"
    "s\0on_EXITButton_released\0"
    "on_label_linkActivated\0link\0"
    "on_disconnectButton_released\0"
    "on_lineEdit_editingFinished\0"
    "on_pushButton_released\0on_playButton_released\0"
    "zmienCounter\0c\0zmienCounter2\0odb_answer\0"
    "readProgress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iDom_Client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   74,    2, 0x08 /* Private */,
       7,    1,   75,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    1,   82,    2, 0x0a /* Public */,
      15,    1,   85,    2, 0x0a /* Public */,
      16,    1,   88,    2, 0x0a /* Public */,
      17,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void iDom_Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        iDom_Client *_t = static_cast<iDom_Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendTCP((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 1: _t->on_EXITButton_released(); break;
        case 2: _t->on_label_linkActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_disconnectButton_released(); break;
        case 4: _t->on_lineEdit_editingFinished(); break;
        case 5: _t->on_pushButton_released(); break;
        case 6: _t->on_playButton_released(); break;
        case 7: _t->zmienCounter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->zmienCounter2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->odb_answer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->readProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (iDom_Client::*_t)(QString , std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&iDom_Client::sendTCP)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject iDom_Client::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_iDom_Client.data,
      qt_meta_data_iDom_Client,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *iDom_Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iDom_Client::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_iDom_Client.stringdata0))
        return static_cast<void*>(const_cast< iDom_Client*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int iDom_Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void iDom_Client::sendTCP(QString _t1, std::string _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
