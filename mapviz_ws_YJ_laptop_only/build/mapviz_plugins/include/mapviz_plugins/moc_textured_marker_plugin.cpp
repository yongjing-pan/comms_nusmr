/****************************************************************************
** Meta object code from reading C++ file 'textured_marker_plugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/mapviz_plugins/include/mapviz_plugins/textured_marker_plugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textured_marker_plugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mapviz_plugins__TexturedMarkerPlugin_t {
    QByteArrayData data[11];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mapviz_plugins__TexturedMarkerPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mapviz_plugins__TexturedMarkerPlugin_t qt_meta_stringdata_mapviz_plugins__TexturedMarkerPlugin = {
    {
QT_MOC_LITERAL(0, 0, 36), // "mapviz_plugins::TexturedMarke..."
QT_MOC_LITERAL(1, 37, 14), // "MarkerReceived"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 45), // "marti_visualization_msgs::msg..."
QT_MOC_LITERAL(4, 99, 6), // "marker"
QT_MOC_LITERAL(5, 106, 13), // "SetAlphaLevel"
QT_MOC_LITERAL(6, 120, 5), // "alpha"
QT_MOC_LITERAL(7, 126, 11), // "SelectTopic"
QT_MOC_LITERAL(8, 138, 11), // "TopicEdited"
QT_MOC_LITERAL(9, 150, 12), // "ClearHistory"
QT_MOC_LITERAL(10, 163, 13) // "ProcessMarker"

    },
    "mapviz_plugins::TexturedMarkerPlugin\0"
    "MarkerReceived\0\0"
    "marti_visualization_msgs::msg::TexturedMarker\0"
    "marker\0SetAlphaLevel\0alpha\0SelectTopic\0"
    "TopicEdited\0ClearHistory\0ProcessMarker"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mapviz_plugins__TexturedMarkerPlugin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x09 /* Protected */,
       7,    0,   50,    2, 0x09 /* Protected */,
       8,    0,   51,    2, 0x09 /* Protected */,
       9,    0,   52,    2, 0x09 /* Protected */,
      10,    1,   53,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void mapviz_plugins::TexturedMarkerPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TexturedMarkerPlugin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->MarkerReceived((*reinterpret_cast< marti_visualization_msgs::msg::TexturedMarker(*)>(_a[1]))); break;
        case 1: _t->SetAlphaLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->SelectTopic(); break;
        case 3: _t->TopicEdited(); break;
        case 4: _t->ClearHistory(); break;
        case 5: _t->ProcessMarker((*reinterpret_cast< marti_visualization_msgs::msg::TexturedMarker(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< marti_visualization_msgs::msg::TexturedMarker >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< marti_visualization_msgs::msg::TexturedMarker >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TexturedMarkerPlugin::*)(marti_visualization_msgs::msg::TexturedMarker );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TexturedMarkerPlugin::MarkerReceived)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mapviz_plugins::TexturedMarkerPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<mapviz::MapvizPlugin::staticMetaObject>(),
    qt_meta_stringdata_mapviz_plugins__TexturedMarkerPlugin.data,
    qt_meta_data_mapviz_plugins__TexturedMarkerPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mapviz_plugins::TexturedMarkerPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mapviz_plugins::TexturedMarkerPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mapviz_plugins__TexturedMarkerPlugin.stringdata0))
        return static_cast<void*>(this);
    return mapviz::MapvizPlugin::qt_metacast(_clname);
}

int mapviz_plugins::TexturedMarkerPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void mapviz_plugins::TexturedMarkerPlugin::MarkerReceived(marti_visualization_msgs::msg::TexturedMarker _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
