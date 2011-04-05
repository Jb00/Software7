/****************************************************************************
** Meta object code from reading C++ file 'genreportwin.h'
**
** Created: Mon Apr 4 21:00:43 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "genreportwin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'genreportwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GenReportWin[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      34,   13,   13,   13, 0x08,
      51,   13,   13,   13, 0x08,
      75,   13,   13,   13, 0x08,
      99,   13,   13,   13, 0x08,
     127,   13,   13,   13, 0x08,
     151,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GenReportWin[] = {
    "GenReportWin\0\0cancelBtn_clicked()\0"
    "genBtn_clicked()\0bedInfoRadio_selected()\0"
    "bedInfoCheck_selected()\0"
    "patientInfoCheck_selected()\0"
    "waitingCheck_selected()\0facilityList_selected()\0"
};

const QMetaObject GenReportWin::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GenReportWin,
      qt_meta_data_GenReportWin, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GenReportWin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GenReportWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GenReportWin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GenReportWin))
        return static_cast<void*>(const_cast< GenReportWin*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GenReportWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: cancelBtn_clicked(); break;
        case 1: genBtn_clicked(); break;
        case 2: bedInfoRadio_selected(); break;
        case 3: bedInfoCheck_selected(); break;
        case 4: patientInfoCheck_selected(); break;
        case 5: waitingCheck_selected(); break;
        case 6: facilityList_selected(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
