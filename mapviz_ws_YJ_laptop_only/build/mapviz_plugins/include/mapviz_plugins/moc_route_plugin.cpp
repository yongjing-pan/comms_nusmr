/****************************************************************************
** Meta object code from reading C++ file 'route_plugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/mapviz_plugins/include/mapviz_plugins/route_plugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'route_plugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mapviz_plugins__RoutePlugin_t {
    QByteArrayData data[9];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mapviz_plugins__RoutePlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mapviz_plugins__RoutePlugin_t qt_meta_stringdata_mapviz_plugins__RoutePlugin = {
    {
QT_MOC_LITERAL(0, 0, 27), // "mapviz_plugins::RoutePlugin"
QT_MOC_LITERAL(1, 28, 11), // "SelectTopic"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 19), // "SelectPositionTopic"
QT_MOC_LITERAL(4, 61, 11), // "TopicEdited"
QT_MOC_LITERAL(5, 73, 19), // "PositionTopicEdited"
QT_MOC_LITERAL(6, 93, 12), // "SetDrawStyle"
QT_MOC_LITERAL(7, 106, 5), // "style"
QT_MOC_LITERAL(8, 112, 8) // "DrawIcon"

    },
    "mapviz_plugins::RoutePlugin\0SelectTopic\0"
    "\0SelectPositionTopic\0TopicEdited\0"
    "PositionTopicEdited\0SetDrawStyle\0style\0"
    "DrawIcon"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mapviz_plugins__RoutePlugin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x09 /* Protected */,
       3,    0,   45,    2, 0x09 /* Protected */,
       4,    0,   46,    2, 0x09 /* Protected */,
       5,    0,   47,    2, 0x09 /* Protected */,
       6,    1,   48,    2, 0x09 /* Protected */,
       8,    0,   51,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void mapviz_plugins::RoutePlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RoutePlugin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SelectTopic(); break;
        case 1: _t->SelectPositionTopic(); break;
        case 2: _t->TopicEdited(); break;
        case 3: _t->PositionTopicEdited(); break;
        case 4: _t->SetDrawStyle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->DrawIcon(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mapviz_plugins::RoutePlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<mapviz::MapvizPlugin::staticMetaObject>(),
    qt_meta_stringdata_mapviz_plugins__RoutePlugin.data,
    qt_meta_data_mapviz_plugins__RoutePlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mapviz_plugins::RoutePlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mapviz_plugins::RoutePlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mapviz_plugins__RoutePlugin.stringdata0))
        return static_cast<void*>(this);
    return mapviz::MapvizPlugin::qt_metacast(_clname);
}

int mapviz_plugins::RoutePlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = mapviz::MapvizPlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
