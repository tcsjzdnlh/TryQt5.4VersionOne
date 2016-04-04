/****************************************************************************
** Meta object code from reading C++ file 'SpreadSheet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SpreadSheet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SpreadSheet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CSpreadSheet_t {
    QByteArrayData data[19];
    char stringdata[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSpreadSheet_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSpreadSheet_t qt_meta_stringdata_CSpreadSheet = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CSpreadSheet"
QT_MOC_LITERAL(1, 13, 8), // "Modified"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "Cut"
QT_MOC_LITERAL(4, 27, 4), // "Copy"
QT_MOC_LITERAL(5, 32, 5), // "Paste"
QT_MOC_LITERAL(6, 38, 3), // "Del"
QT_MOC_LITERAL(7, 42, 16), // "SelectCurrentRow"
QT_MOC_LITERAL(8, 59, 19), // "SelectCurrentColumn"
QT_MOC_LITERAL(9, 79, 9), // "SelectAll"
QT_MOC_LITERAL(10, 89, 11), // "Recalculate"
QT_MOC_LITERAL(11, 101, 18), // "SetAutoRecalculate"
QT_MOC_LITERAL(12, 120, 2), // "_b"
QT_MOC_LITERAL(13, 123, 8), // "FindNext"
QT_MOC_LITERAL(14, 132, 4), // "_str"
QT_MOC_LITERAL(15, 137, 19), // "Qt::CaseSensitivity"
QT_MOC_LITERAL(16, 157, 5), // "_uorl"
QT_MOC_LITERAL(17, 163, 12), // "FindPrevious"
QT_MOC_LITERAL(18, 176, 16) // "SomethingChanged"

    },
    "CSpreadSheet\0Modified\0\0Cut\0Copy\0Paste\0"
    "Del\0SelectCurrentRow\0SelectCurrentColumn\0"
    "SelectAll\0Recalculate\0SetAutoRecalculate\0"
    "_b\0FindNext\0_str\0Qt::CaseSensitivity\0"
    "_uorl\0FindPrevious\0SomethingChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSpreadSheet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   80,    2, 0x0a /* Public */,
       4,    0,   81,    2, 0x0a /* Public */,
       5,    0,   82,    2, 0x0a /* Public */,
       6,    0,   83,    2, 0x0a /* Public */,
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    1,   88,    2, 0x0a /* Public */,
      13,    2,   91,    2, 0x0a /* Public */,
      17,    2,   96,    2, 0x0a /* Public */,
      18,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 15,   14,   16,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 15,   14,   16,
    QMetaType::Void,

       0        // eod
};

void CSpreadSheet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSpreadSheet *_t = static_cast<CSpreadSheet *>(_o);
        switch (_id) {
        case 0: _t->Modified(); break;
        case 1: _t->Cut(); break;
        case 2: _t->Copy(); break;
        case 3: _t->Paste(); break;
        case 4: _t->Del(); break;
        case 5: _t->SelectCurrentRow(); break;
        case 6: _t->SelectCurrentColumn(); break;
        case 7: _t->SelectAll(); break;
        case 8: _t->Recalculate(); break;
        case 9: _t->SetAutoRecalculate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->FindNext((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::CaseSensitivity(*)>(_a[2]))); break;
        case 11: _t->FindPrevious((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::CaseSensitivity(*)>(_a[2]))); break;
        case 12: _t->SomethingChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSpreadSheet::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSpreadSheet::Modified)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CSpreadSheet::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_CSpreadSheet.data,
      qt_meta_data_CSpreadSheet,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CSpreadSheet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSpreadSheet::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CSpreadSheet.stringdata))
        return static_cast<void*>(const_cast< CSpreadSheet*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int CSpreadSheet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void CSpreadSheet::Modified()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
