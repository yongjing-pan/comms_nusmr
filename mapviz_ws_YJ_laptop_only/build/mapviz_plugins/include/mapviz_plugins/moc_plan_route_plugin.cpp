/****************************************************************************
** Meta object code from reading C++ file 'plan_route_plugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/mapviz_plugins/include/mapviz_plugins/plan_route_plugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plan_route_plugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mapviz_plugins__PlanRoutePlugin_t {
    QByteArrayData data[6];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mapviz_plugins__PlanRoutePlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mapviz_plugins__PlanRoutePlugin_t qt_meta_stringdata_mapviz_plugins__PlanRoutePlugin = {
    {
QT_MOC_LITERAL(0, 0, 31), // "mapviz_plugins::PlanRoutePlugin"
QT_MOC_LITERAL(1, 32, 12), // "PublishRoute"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 9), // "PlanRoute"
QT_MOC_LITERAL(4, 56, 5), // "Clear"
QT_MOC_LITERAL(5, 62, 17) // "VisibilityChanged"

    },
    "mapviz_plugins::PlanRoutePlugin\0"
    "PublishRoute\0\0PlanRoute\0Clear\0"
    "VisibilityChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mapviz_plugins__PlanRoutePlugin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x09 /* Protected */,
       3,    0,   35,    2, 0x09 /* Protected */,
       4,    0,   36,    2, 0x09 /* Protected */,
       5,    1,   37,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void mapviz_plugins::PlanRoutePlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlanRoutePlugin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->PublishRoute(); break;
        case 1: _t->PlanRoute(); break;
        case 2: _t->Clear(); break;
        case 3: _t->VisibilityChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mapviz_plugins::PlanRoutePlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<mapviz::MapvizPlugin::staticMetaObject>(),
    qt_meta_stringdata_mapviz_plugins__PlanRoutePlugin.data,
    qt_meta_data_mapviz_plugins__PlanRoutePlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mapviz_plugins::PlanRoutePlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mapviz_plugins::PlanRoutePlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mapviz_plugins__PlanRoutePlugin.stringdata0))
        return static_cast<void*>(this);
    return mapviz::MapvizPlugin::qt_metacast(_clname);
}

int mapviz_plugins::PlanRoutePlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = mapviz::MapvizPlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
