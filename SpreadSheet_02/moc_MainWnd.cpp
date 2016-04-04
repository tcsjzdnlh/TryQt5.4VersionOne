/****************************************************************************
** Meta object code from reading C++ file 'MainWnd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWnd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWnd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CMainWnd_t {
    QByteArrayData data[14];
    char stringdata[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMainWnd_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMainWnd_t qt_meta_stringdata_CMainWnd = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CMainWnd"
QT_MOC_LITERAL(1, 9, 7), // "NewFile"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "OpenFile"
QT_MOC_LITERAL(4, 27, 14), // "OpenRecentFile"
QT_MOC_LITERAL(5, 42, 4), // "Save"
QT_MOC_LITERAL(6, 47, 6), // "SaveAs"
QT_MOC_LITERAL(7, 54, 4), // "Exit"
QT_MOC_LITERAL(8, 59, 4), // "Find"
QT_MOC_LITERAL(9, 64, 8), // "GoToCell"
QT_MOC_LITERAL(10, 73, 4), // "Sort"
QT_MOC_LITERAL(11, 78, 5), // "About"
QT_MOC_LITERAL(12, 84, 15), // "UpdateStatusBar"
QT_MOC_LITERAL(13, 100, 19) // "SpreadSheetModified"

    },
    "CMainWnd\0NewFile\0\0OpenFile\0OpenRecentFile\0"
    "Save\0SaveAs\0Exit\0Find\0GoToCell\0Sort\0"
    "About\0UpdateStatusBar\0SpreadSheetModified"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMainWnd[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CMainWnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMainWnd *_t = static_cast<CMainWnd *>(_o);
        switch (_id) {
        case 0: _t->NewFile(); break;
        case 1: _t->OpenFile(); break;
        case 2: _t->OpenRecentFile(); break;
        case 3: { bool _r = _t->Save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->SaveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->Exit(); break;
        case 6: _t->Find(); break;
        case 7: _t->GoToCell(); break;
        case 8: _t->Sort(); break;
        case 9: _t->About(); break;
        case 10: _t->UpdateStatusBar(); break;
        case 11: _t->SpreadSheetModified(); break;
        default: ;
        }
    }
}

const QMetaObject CMainWnd::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CMainWnd.data,
      qt_meta_data_CMainWnd,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CMainWnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMainWnd::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CMainWnd.stringdata))
        return static_cast<void*>(const_cast< CMainWnd*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CMainWnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
