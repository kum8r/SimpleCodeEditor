/****************************************************************************
** Meta object code from reading C++ file 'finddialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/finddialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'finddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_findDialog_t {
    QByteArrayData data[19];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_findDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_findDialog_t qt_meta_stringdata_findDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "findDialog"
QT_MOC_LITERAL(1, 11, 18), // "findButton_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "searchtext"
QT_MOC_LITERAL(4, 42, 16), // "findPrev_clicked"
QT_MOC_LITERAL(5, 59, 17), // "findStringChanged"
QT_MOC_LITERAL(6, 77, 15), // "replace_clicked"
QT_MOC_LITERAL(7, 93, 11), // "replacetext"
QT_MOC_LITERAL(8, 105, 18), // "replaceAll_clicked"
QT_MOC_LITERAL(9, 124, 15), // "closeFindDialog"
QT_MOC_LITERAL(10, 140, 18), // "on_FindBtn_clicked"
QT_MOC_LITERAL(11, 159, 22), // "on_FindPrevBtn_clicked"
QT_MOC_LITERAL(12, 182, 21), // "on_replaceBtn_clicked"
QT_MOC_LITERAL(13, 204, 24), // "on_replaceAllBtn_clicked"
QT_MOC_LITERAL(14, 229, 23), // "on_findCloseBtn_clicked"
QT_MOC_LITERAL(15, 253, 26), // "on_replaceCloseBtn_clicked"
QT_MOC_LITERAL(16, 280, 27), // "on_findString_returnPressed"
QT_MOC_LITERAL(17, 308, 25), // "on_findString_textChanged"
QT_MOC_LITERAL(18, 334, 4) // "arg1"

    },
    "findDialog\0findButton_clicked\0\0"
    "searchtext\0findPrev_clicked\0"
    "findStringChanged\0replace_clicked\0"
    "replacetext\0replaceAll_clicked\0"
    "closeFindDialog\0on_FindBtn_clicked\0"
    "on_FindPrevBtn_clicked\0on_replaceBtn_clicked\0"
    "on_replaceAllBtn_clicked\0"
    "on_findCloseBtn_clicked\0"
    "on_replaceCloseBtn_clicked\0"
    "on_findString_returnPressed\0"
    "on_findString_textChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_findDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       5,    0,   90,    2, 0x06 /* Public */,
       6,    1,   91,    2, 0x06 /* Public */,
       8,    2,   94,    2, 0x06 /* Public */,
       9,    0,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  100,    2, 0x08 /* Private */,
      11,    0,  101,    2, 0x08 /* Private */,
      12,    0,  102,    2, 0x08 /* Private */,
      13,    0,  103,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,
      16,    0,  106,    2, 0x08 /* Private */,
      17,    1,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,

       0        // eod
};

void findDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<findDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->findButton_clicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->findPrev_clicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->findStringChanged(); break;
        case 3: _t->replace_clicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->replaceAll_clicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->closeFindDialog(); break;
        case 6: _t->on_FindBtn_clicked(); break;
        case 7: _t->on_FindPrevBtn_clicked(); break;
        case 8: _t->on_replaceBtn_clicked(); break;
        case 9: _t->on_replaceAllBtn_clicked(); break;
        case 10: _t->on_findCloseBtn_clicked(); break;
        case 11: _t->on_replaceCloseBtn_clicked(); break;
        case 12: _t->on_findString_returnPressed(); break;
        case 13: _t->on_findString_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (findDialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&findDialog::findButton_clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (findDialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&findDialog::findPrev_clicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (findDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&findDialog::findStringChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (findDialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&findDialog::replace_clicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (findDialog::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&findDialog::replaceAll_clicked)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (findDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&findDialog::closeFindDialog)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject findDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_findDialog.data,
    qt_meta_data_findDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *findDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *findDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_findDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int findDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void findDialog::findButton_clicked(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void findDialog::findPrev_clicked(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void findDialog::findStringChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void findDialog::replace_clicked(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void findDialog::replaceAll_clicked(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void findDialog::closeFindDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
