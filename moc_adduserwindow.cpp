/****************************************************************************
** Meta object code from reading C++ file 'adduserwindow.h'
**
** Created: Mon Apr 4 00:49:58 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "adduserwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adduserwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddUserWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      38,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddUserWindow[] = {
    "AddUserWindow\0\0on_cancelBtn_clicked()\0"
    "on_okBtn_clicked()\0"
};

const QMetaObject AddUserWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AddUserWindow,
      qt_meta_data_AddUserWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddUserWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddUserWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddUserWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddUserWindow))
        return static_cast<void*>(const_cast< AddUserWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AddUserWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_cancelBtn_clicked(); break;
        case 1: on_okBtn_clicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
