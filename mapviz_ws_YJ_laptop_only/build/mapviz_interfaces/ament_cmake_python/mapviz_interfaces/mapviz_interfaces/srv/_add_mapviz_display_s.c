// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from mapviz_interfaces:srv/AddMapvizDisplay.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "mapviz_interfaces/srv/detail/add_mapviz_display__struct.h"
#include "mapviz_interfaces/srv/detail/add_mapviz_display__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "marti_common_msgs/msg/detail/key_value__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool marti_common_msgs__msg__key_value__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * marti_common_msgs__msg__key_value__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool mapviz_interfaces__srv__add_mapviz_display__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[67];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("mapviz_interfaces.srv._add_mapviz_display.AddMapvizDisplay_Request", full_classname_dest, 66) == 0);
  }
  mapviz_interfaces__srv__AddMapvizDisplay_Request * ros_message = _ros_message;
  {  // name
    PyObject * field = PyObject_GetAttrString(_pymsg, "name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // type
    PyObject * field = PyObject_GetAttrString(_pymsg, "type");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->type, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // draw_order
    PyObject * field = PyObject_GetAttrString(_pymsg, "draw_order");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->draw_order = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // visible
    PyObject * field = PyObject_GetAttrString(_pymsg, "visible");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->visible = (Py_True == field);
    Py_DECREF(field);
  }
  {  // properties
    PyObject * field = PyObject_GetAttrString(_pymsg, "properties");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'properties'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!marti_common_msgs__msg__KeyValue__Sequence__init(&(ros_message->properties), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create marti_common_msgs__msg__KeyValue__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    marti_common_msgs__msg__KeyValue * dest = ros_message->properties.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!marti_common_msgs__msg__key_value__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * mapviz_interfaces__srv__add_mapviz_display__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AddMapvizDisplay_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("mapviz_interfaces.srv._add_mapviz_display");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AddMapvizDisplay_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  mapviz_interfaces__srv__AddMapvizDisplay_Request * ros_message = (mapviz_interfaces__srv__AddMapvizDisplay_Request *)raw_ros_message;
  {  // name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->name.data,
      strlen(ros_message->name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // type
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->type.data,
      strlen(ros_message->type.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // draw_order
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->draw_order);
    {
      int rc = PyObject_SetAttrString(_pymessage, "draw_order", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // visible
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->visible ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "visible", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // properties
    PyObject * field = NULL;
    size_t size = ros_message->properties.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    marti_common_msgs__msg__KeyValue * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->properties.data[i]);
      PyObject * pyitem = marti_common_msgs__msg__key_value__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "properties", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "mapviz_interfaces/srv/detail/add_mapviz_display__struct.h"
// already included above
// #include "mapviz_interfaces/srv/detail/add_mapviz_display__functions.h"

// already included above
// #include "rosidl_runtime_c/string.h"
// already included above
// #include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool mapviz_interfaces__srv__add_mapviz_display__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[68];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("mapviz_interfaces.srv._add_mapviz_display.AddMapvizDisplay_Response", full_classname_dest, 67) == 0);
  }
  mapviz_interfaces__srv__AddMapvizDisplay_Response * ros_message = _ros_message;
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }
  {  // message
    PyObject * field = PyObject_GetAttrString(_pymsg, "message");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->message, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * mapviz_interfaces__srv__add_mapviz_display__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AddMapvizDisplay_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("mapviz_interfaces.srv._add_mapviz_display");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AddMapvizDisplay_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  mapviz_interfaces__srv__AddMapvizDisplay_Response * ros_message = (mapviz_interfaces__srv__AddMapvizDisplay_Response *)raw_ros_message;
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // message
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->message.data,
      strlen(ros_message->message.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "message", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
