/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[103];
    char stringdata0[2409];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 5), // "print"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 9), // "QPrinter*"
QT_MOC_LITERAL(4, 28, 7), // "printer"
QT_MOC_LITERAL(5, 36, 9), // "lostFocus"
QT_MOC_LITERAL(6, 46, 7), // "QEvent*"
QT_MOC_LITERAL(7, 54, 5), // "event"
QT_MOC_LITERAL(8, 60, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(9, 83, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(10, 107, 32), // "on_actionOpenDirectory_triggered"
QT_MOC_LITERAL(11, 140, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(12, 164, 26), // "on_actionSave_AS_triggered"
QT_MOC_LITERAL(13, 191, 27), // "on_actionSave_All_triggered"
QT_MOC_LITERAL(14, 219, 24), // "on_actionPrint_triggered"
QT_MOC_LITERAL(15, 244, 32), // "on_actionPrint_Preview_triggered"
QT_MOC_LITERAL(16, 277, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(17, 302, 30), // "on_tabWidget_tabCloseRequested"
QT_MOC_LITERAL(18, 333, 5), // "index"
QT_MOC_LITERAL(19, 339, 34), // "on_actionClose_All_Files_trig..."
QT_MOC_LITERAL(20, 374, 29), // "on_actionNew_Window_triggered"
QT_MOC_LITERAL(21, 404, 31), // "on_actionClose_Window_triggered"
QT_MOC_LITERAL(22, 436, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(23, 460, 23), // "on_actionUndo_triggered"
QT_MOC_LITERAL(24, 484, 23), // "on_actionRedo_triggered"
QT_MOC_LITERAL(25, 508, 22), // "on_actionCut_triggered"
QT_MOC_LITERAL(26, 531, 23), // "on_actionCopy_triggered"
QT_MOC_LITERAL(27, 555, 24), // "on_actionPaste_triggered"
QT_MOC_LITERAL(28, 580, 29), // "on_actionSelect_All_triggered"
QT_MOC_LITERAL(29, 610, 27), // "on_actionDeselect_triggered"
QT_MOC_LITERAL(30, 638, 23), // "on_actionFind_triggered"
QT_MOC_LITERAL(31, 662, 28), // "on_actionFind_Prev_triggered"
QT_MOC_LITERAL(32, 691, 26), // "on_actionReplace_triggered"
QT_MOC_LITERAL(33, 718, 30), // "on_actionReplace_All_triggered"
QT_MOC_LITERAL(34, 749, 18), // "findButton_clicked"
QT_MOC_LITERAL(35, 768, 10), // "searchtext"
QT_MOC_LITERAL(36, 779, 16), // "findPrev_clicked"
QT_MOC_LITERAL(37, 796, 15), // "replace_clicked"
QT_MOC_LITERAL(38, 812, 18), // "replaceAll_clicked"
QT_MOC_LITERAL(39, 831, 15), // "closeFindDialog"
QT_MOC_LITERAL(40, 847, 31), // "on_actionOpened_Files_triggered"
QT_MOC_LITERAL(41, 879, 32), // "on_actionFile_Explorer_triggered"
QT_MOC_LITERAL(42, 912, 22), // "on_actionMac_triggered"
QT_MOC_LITERAL(43, 935, 23), // "on_actionUnix_triggered"
QT_MOC_LITERAL(44, 959, 26), // "on_actionWindows_triggered"
QT_MOC_LITERAL(45, 986, 35), // "on_actionShow_Linenumbers_tri..."
QT_MOC_LITERAL(46, 1022, 28), // "on_actionStatusBar_triggered"
QT_MOC_LITERAL(47, 1051, 26), // "on_actionToolBar_triggered"
QT_MOC_LITERAL(48, 1078, 25), // "on_actionNormal_triggered"
QT_MOC_LITERAL(49, 1104, 23), // "on_actionBash_triggered"
QT_MOC_LITERAL(50, 1128, 29), // "on_actionBatch_File_triggered"
QT_MOC_LITERAL(51, 1158, 20), // "on_actionC_triggered"
QT_MOC_LITERAL(52, 1179, 25), // "on_actionCSharp_triggered"
QT_MOC_LITERAL(53, 1205, 22), // "on_actionCpp_triggered"
QT_MOC_LITERAL(54, 1228, 22), // "on_actionCSS_triggered"
QT_MOC_LITERAL(55, 1251, 24), // "on_actionCMake_triggered"
QT_MOC_LITERAL(56, 1276, 31), // "on_actionCoffeeScript_triggered"
QT_MOC_LITERAL(57, 1308, 20), // "on_actionD_triggered"
QT_MOC_LITERAL(58, 1329, 23), // "on_actionDiff_triggered"
QT_MOC_LITERAL(59, 1353, 25), // "on_actionFortan_triggered"
QT_MOC_LITERAL(60, 1379, 27), // "on_actionFortan77_triggered"
QT_MOC_LITERAL(61, 1407, 23), // "on_actionHTML_triggered"
QT_MOC_LITERAL(62, 1431, 23), // "on_actionJava_triggered"
QT_MOC_LITERAL(63, 1455, 29), // "on_actionJavaScript_triggered"
QT_MOC_LITERAL(64, 1485, 23), // "on_actionJSON_triggered"
QT_MOC_LITERAL(65, 1509, 22), // "on_actionLua_triggered"
QT_MOC_LITERAL(66, 1532, 27), // "on_actionMarkDown_triggered"
QT_MOC_LITERAL(67, 1560, 27), // "on_actionMakeFile_triggered"
QT_MOC_LITERAL(68, 1588, 25), // "on_actionMatLab_triggered"
QT_MOC_LITERAL(69, 1614, 25), // "on_actionPascal_triggered"
QT_MOC_LITERAL(70, 1640, 25), // "on_actionPython_triggered"
QT_MOC_LITERAL(71, 1666, 23), // "on_actionPerl_triggered"
QT_MOC_LITERAL(72, 1690, 29), // "on_actionProperties_triggered"
QT_MOC_LITERAL(73, 1720, 23), // "on_actionRuby_triggered"
QT_MOC_LITERAL(74, 1744, 22), // "on_actionSQL_triggered"
QT_MOC_LITERAL(75, 1767, 22), // "on_actionTeX_triggered"
QT_MOC_LITERAL(76, 1790, 22), // "on_actionXML_triggered"
QT_MOC_LITERAL(77, 1813, 23), // "on_actionYAML_triggered"
QT_MOC_LITERAL(78, 1837, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(79, 1862, 27), // "on_actionAbout_QT_triggered"
QT_MOC_LITERAL(80, 1890, 25), // "on_treeView_doubleClicked"
QT_MOC_LITERAL(81, 1916, 11), // "QModelIndex"
QT_MOC_LITERAL(82, 1928, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(83, 1956, 31), // "on_listWidget_itemDoubleClicked"
QT_MOC_LITERAL(84, 1988, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(85, 2005, 4), // "item"
QT_MOC_LITERAL(86, 2010, 8), // "setLexer"
QT_MOC_LITERAL(87, 2019, 9), // "lexername"
QT_MOC_LITERAL(88, 2029, 27), // "on_actionWordWrap_triggered"
QT_MOC_LITERAL(89, 2057, 29), // "on_actionAdd_Indent_triggered"
QT_MOC_LITERAL(90, 2087, 27), // "on_actionSettings_triggered"
QT_MOC_LITERAL(91, 2115, 33), // "on_actionDuplicate_Line_trigg..."
QT_MOC_LITERAL(92, 2149, 18), // "findString_Changed"
QT_MOC_LITERAL(93, 2168, 29), // "on_actionUPPER_CASE_triggered"
QT_MOC_LITERAL(94, 2198, 29), // "on_actionlower_case_triggered"
QT_MOC_LITERAL(95, 2228, 29), // "on_actionGo_to_Line_triggered"
QT_MOC_LITERAL(96, 2258, 34), // "on_actionDecrease_Indent_trig..."
QT_MOC_LITERAL(97, 2293, 16), // "setTextinMinimap"
QT_MOC_LITERAL(98, 2310, 31), // "on_actionShow_Minimap_triggered"
QT_MOC_LITERAL(99, 2342, 23), // "on_actionDark_triggered"
QT_MOC_LITERAL(100, 2366, 24), // "on_actionLight_triggered"
QT_MOC_LITERAL(101, 2391, 8), // "openFile"
QT_MOC_LITERAL(102, 2400, 8) // "filepath"

    },
    "MainWindow\0print\0\0QPrinter*\0printer\0"
    "lostFocus\0QEvent*\0event\0on_actionNew_triggered\0"
    "on_actionOpen_triggered\0"
    "on_actionOpenDirectory_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionSave_AS_triggered\0"
    "on_actionSave_All_triggered\0"
    "on_actionPrint_triggered\0"
    "on_actionPrint_Preview_triggered\0"
    "on_actionClose_triggered\0"
    "on_tabWidget_tabCloseRequested\0index\0"
    "on_actionClose_All_Files_triggered\0"
    "on_actionNew_Window_triggered\0"
    "on_actionClose_Window_triggered\0"
    "on_actionExit_triggered\0on_actionUndo_triggered\0"
    "on_actionRedo_triggered\0on_actionCut_triggered\0"
    "on_actionCopy_triggered\0"
    "on_actionPaste_triggered\0"
    "on_actionSelect_All_triggered\0"
    "on_actionDeselect_triggered\0"
    "on_actionFind_triggered\0"
    "on_actionFind_Prev_triggered\0"
    "on_actionReplace_triggered\0"
    "on_actionReplace_All_triggered\0"
    "findButton_clicked\0searchtext\0"
    "findPrev_clicked\0replace_clicked\0"
    "replaceAll_clicked\0closeFindDialog\0"
    "on_actionOpened_Files_triggered\0"
    "on_actionFile_Explorer_triggered\0"
    "on_actionMac_triggered\0on_actionUnix_triggered\0"
    "on_actionWindows_triggered\0"
    "on_actionShow_Linenumbers_triggered\0"
    "on_actionStatusBar_triggered\0"
    "on_actionToolBar_triggered\0"
    "on_actionNormal_triggered\0"
    "on_actionBash_triggered\0"
    "on_actionBatch_File_triggered\0"
    "on_actionC_triggered\0on_actionCSharp_triggered\0"
    "on_actionCpp_triggered\0on_actionCSS_triggered\0"
    "on_actionCMake_triggered\0"
    "on_actionCoffeeScript_triggered\0"
    "on_actionD_triggered\0on_actionDiff_triggered\0"
    "on_actionFortan_triggered\0"
    "on_actionFortan77_triggered\0"
    "on_actionHTML_triggered\0on_actionJava_triggered\0"
    "on_actionJavaScript_triggered\0"
    "on_actionJSON_triggered\0on_actionLua_triggered\0"
    "on_actionMarkDown_triggered\0"
    "on_actionMakeFile_triggered\0"
    "on_actionMatLab_triggered\0"
    "on_actionPascal_triggered\0"
    "on_actionPython_triggered\0"
    "on_actionPerl_triggered\0"
    "on_actionProperties_triggered\0"
    "on_actionRuby_triggered\0on_actionSQL_triggered\0"
    "on_actionTeX_triggered\0on_actionXML_triggered\0"
    "on_actionYAML_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionAbout_QT_triggered\0"
    "on_treeView_doubleClicked\0QModelIndex\0"
    "on_tabWidget_currentChanged\0"
    "on_listWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0setLexer\0lexername\0"
    "on_actionWordWrap_triggered\0"
    "on_actionAdd_Indent_triggered\0"
    "on_actionSettings_triggered\0"
    "on_actionDuplicate_Line_triggered\0"
    "findString_Changed\0on_actionUPPER_CASE_triggered\0"
    "on_actionlower_case_triggered\0"
    "on_actionGo_to_Line_triggered\0"
    "on_actionDecrease_Indent_triggered\0"
    "setTextinMinimap\0on_actionShow_Minimap_triggered\0"
    "on_actionDark_triggered\0"
    "on_actionLight_triggered\0openFile\0"
    "filepath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      91,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  469,    2, 0x08 /* Private */,
       5,    1,  472,    2, 0x08 /* Private */,
       8,    0,  475,    2, 0x08 /* Private */,
       9,    0,  476,    2, 0x08 /* Private */,
      10,    0,  477,    2, 0x08 /* Private */,
      11,    0,  478,    2, 0x08 /* Private */,
      12,    0,  479,    2, 0x08 /* Private */,
      13,    0,  480,    2, 0x08 /* Private */,
      14,    0,  481,    2, 0x08 /* Private */,
      15,    0,  482,    2, 0x08 /* Private */,
      16,    0,  483,    2, 0x08 /* Private */,
      17,    1,  484,    2, 0x08 /* Private */,
      19,    0,  487,    2, 0x08 /* Private */,
      20,    0,  488,    2, 0x08 /* Private */,
      21,    0,  489,    2, 0x08 /* Private */,
      22,    0,  490,    2, 0x08 /* Private */,
      23,    0,  491,    2, 0x08 /* Private */,
      24,    0,  492,    2, 0x08 /* Private */,
      25,    0,  493,    2, 0x08 /* Private */,
      26,    0,  494,    2, 0x08 /* Private */,
      27,    0,  495,    2, 0x08 /* Private */,
      28,    0,  496,    2, 0x08 /* Private */,
      29,    0,  497,    2, 0x08 /* Private */,
      30,    0,  498,    2, 0x08 /* Private */,
      31,    0,  499,    2, 0x08 /* Private */,
      32,    0,  500,    2, 0x08 /* Private */,
      33,    0,  501,    2, 0x08 /* Private */,
      34,    1,  502,    2, 0x08 /* Private */,
      36,    1,  505,    2, 0x08 /* Private */,
      37,    1,  508,    2, 0x08 /* Private */,
      38,    2,  511,    2, 0x08 /* Private */,
      39,    0,  516,    2, 0x08 /* Private */,
      40,    0,  517,    2, 0x08 /* Private */,
      41,    0,  518,    2, 0x08 /* Private */,
      42,    0,  519,    2, 0x08 /* Private */,
      43,    0,  520,    2, 0x08 /* Private */,
      44,    0,  521,    2, 0x08 /* Private */,
      45,    0,  522,    2, 0x08 /* Private */,
      46,    0,  523,    2, 0x08 /* Private */,
      47,    0,  524,    2, 0x08 /* Private */,
      48,    0,  525,    2, 0x08 /* Private */,
      49,    0,  526,    2, 0x08 /* Private */,
      50,    0,  527,    2, 0x08 /* Private */,
      51,    0,  528,    2, 0x08 /* Private */,
      52,    0,  529,    2, 0x08 /* Private */,
      53,    0,  530,    2, 0x08 /* Private */,
      54,    0,  531,    2, 0x08 /* Private */,
      55,    0,  532,    2, 0x08 /* Private */,
      56,    0,  533,    2, 0x08 /* Private */,
      57,    0,  534,    2, 0x08 /* Private */,
      58,    0,  535,    2, 0x08 /* Private */,
      59,    0,  536,    2, 0x08 /* Private */,
      60,    0,  537,    2, 0x08 /* Private */,
      61,    0,  538,    2, 0x08 /* Private */,
      62,    0,  539,    2, 0x08 /* Private */,
      63,    0,  540,    2, 0x08 /* Private */,
      64,    0,  541,    2, 0x08 /* Private */,
      65,    0,  542,    2, 0x08 /* Private */,
      66,    0,  543,    2, 0x08 /* Private */,
      67,    0,  544,    2, 0x08 /* Private */,
      68,    0,  545,    2, 0x08 /* Private */,
      69,    0,  546,    2, 0x08 /* Private */,
      70,    0,  547,    2, 0x08 /* Private */,
      71,    0,  548,    2, 0x08 /* Private */,
      72,    0,  549,    2, 0x08 /* Private */,
      73,    0,  550,    2, 0x08 /* Private */,
      74,    0,  551,    2, 0x08 /* Private */,
      75,    0,  552,    2, 0x08 /* Private */,
      76,    0,  553,    2, 0x08 /* Private */,
      77,    0,  554,    2, 0x08 /* Private */,
      78,    0,  555,    2, 0x08 /* Private */,
      79,    0,  556,    2, 0x08 /* Private */,
      80,    1,  557,    2, 0x08 /* Private */,
      82,    1,  560,    2, 0x08 /* Private */,
      83,    1,  563,    2, 0x08 /* Private */,
      86,    1,  566,    2, 0x08 /* Private */,
      88,    0,  569,    2, 0x08 /* Private */,
      89,    0,  570,    2, 0x08 /* Private */,
      90,    0,  571,    2, 0x08 /* Private */,
      91,    0,  572,    2, 0x08 /* Private */,
      92,    0,  573,    2, 0x08 /* Private */,
      93,    0,  574,    2, 0x08 /* Private */,
      94,    0,  575,    2, 0x08 /* Private */,
      95,    0,  576,    2, 0x08 /* Private */,
      96,    0,  577,    2, 0x08 /* Private */,
      97,    0,  578,    2, 0x08 /* Private */,
      98,    0,  579,    2, 0x08 /* Private */,
      99,    0,  580,    2, 0x08 /* Private */,
     100,    0,  581,    2, 0x08 /* Private */,
     101,    1,  582,    2, 0x0a /* Public */,
     101,    0,  585,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   35,
    QMetaType::Void, QMetaType::QString,   35,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 81,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, 0x80000000 | 84,   85,
    QMetaType::Void, QMetaType::QString,   87,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  102,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->print((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        case 1: _t->lostFocus((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 2: _t->on_actionNew_triggered(); break;
        case 3: _t->on_actionOpen_triggered(); break;
        case 4: _t->on_actionOpenDirectory_triggered(); break;
        case 5: _t->on_actionSave_triggered(); break;
        case 6: _t->on_actionSave_AS_triggered(); break;
        case 7: _t->on_actionSave_All_triggered(); break;
        case 8: _t->on_actionPrint_triggered(); break;
        case 9: _t->on_actionPrint_Preview_triggered(); break;
        case 10: _t->on_actionClose_triggered(); break;
        case 11: _t->on_tabWidget_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_actionClose_All_Files_triggered(); break;
        case 13: _t->on_actionNew_Window_triggered(); break;
        case 14: _t->on_actionClose_Window_triggered(); break;
        case 15: _t->on_actionExit_triggered(); break;
        case 16: _t->on_actionUndo_triggered(); break;
        case 17: _t->on_actionRedo_triggered(); break;
        case 18: _t->on_actionCut_triggered(); break;
        case 19: _t->on_actionCopy_triggered(); break;
        case 20: _t->on_actionPaste_triggered(); break;
        case 21: _t->on_actionSelect_All_triggered(); break;
        case 22: _t->on_actionDeselect_triggered(); break;
        case 23: _t->on_actionFind_triggered(); break;
        case 24: _t->on_actionFind_Prev_triggered(); break;
        case 25: _t->on_actionReplace_triggered(); break;
        case 26: _t->on_actionReplace_All_triggered(); break;
        case 27: _t->findButton_clicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->findPrev_clicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->replace_clicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: _t->replaceAll_clicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 31: _t->closeFindDialog(); break;
        case 32: _t->on_actionOpened_Files_triggered(); break;
        case 33: _t->on_actionFile_Explorer_triggered(); break;
        case 34: _t->on_actionMac_triggered(); break;
        case 35: _t->on_actionUnix_triggered(); break;
        case 36: _t->on_actionWindows_triggered(); break;
        case 37: _t->on_actionShow_Linenumbers_triggered(); break;
        case 38: _t->on_actionStatusBar_triggered(); break;
        case 39: _t->on_actionToolBar_triggered(); break;
        case 40: _t->on_actionNormal_triggered(); break;
        case 41: _t->on_actionBash_triggered(); break;
        case 42: _t->on_actionBatch_File_triggered(); break;
        case 43: _t->on_actionC_triggered(); break;
        case 44: _t->on_actionCSharp_triggered(); break;
        case 45: _t->on_actionCpp_triggered(); break;
        case 46: _t->on_actionCSS_triggered(); break;
        case 47: _t->on_actionCMake_triggered(); break;
        case 48: _t->on_actionCoffeeScript_triggered(); break;
        case 49: _t->on_actionD_triggered(); break;
        case 50: _t->on_actionDiff_triggered(); break;
        case 51: _t->on_actionFortan_triggered(); break;
        case 52: _t->on_actionFortan77_triggered(); break;
        case 53: _t->on_actionHTML_triggered(); break;
        case 54: _t->on_actionJava_triggered(); break;
        case 55: _t->on_actionJavaScript_triggered(); break;
        case 56: _t->on_actionJSON_triggered(); break;
        case 57: _t->on_actionLua_triggered(); break;
        case 58: _t->on_actionMarkDown_triggered(); break;
        case 59: _t->on_actionMakeFile_triggered(); break;
        case 60: _t->on_actionMatLab_triggered(); break;
        case 61: _t->on_actionPascal_triggered(); break;
        case 62: _t->on_actionPython_triggered(); break;
        case 63: _t->on_actionPerl_triggered(); break;
        case 64: _t->on_actionProperties_triggered(); break;
        case 65: _t->on_actionRuby_triggered(); break;
        case 66: _t->on_actionSQL_triggered(); break;
        case 67: _t->on_actionTeX_triggered(); break;
        case 68: _t->on_actionXML_triggered(); break;
        case 69: _t->on_actionYAML_triggered(); break;
        case 70: _t->on_actionAbout_triggered(); break;
        case 71: _t->on_actionAbout_QT_triggered(); break;
        case 72: _t->on_treeView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 73: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 74: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 75: _t->setLexer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 76: _t->on_actionWordWrap_triggered(); break;
        case 77: _t->on_actionAdd_Indent_triggered(); break;
        case 78: _t->on_actionSettings_triggered(); break;
        case 79: _t->on_actionDuplicate_Line_triggered(); break;
        case 80: _t->findString_Changed(); break;
        case 81: _t->on_actionUPPER_CASE_triggered(); break;
        case 82: _t->on_actionlower_case_triggered(); break;
        case 83: _t->on_actionGo_to_Line_triggered(); break;
        case 84: _t->on_actionDecrease_Indent_triggered(); break;
        case 85: _t->setTextinMinimap(); break;
        case 86: _t->on_actionShow_Minimap_triggered(); break;
        case 87: _t->on_actionDark_triggered(); break;
        case 88: _t->on_actionLight_triggered(); break;
        case 89: _t->openFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 90: _t->openFile(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 91)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 91;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 91)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 91;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
