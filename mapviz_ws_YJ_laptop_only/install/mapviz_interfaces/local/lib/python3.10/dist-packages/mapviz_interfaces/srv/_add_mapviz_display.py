# generated from rosidl_generator_py/resource/_idl.py.em
# with input from mapviz_interfaces:srv/AddMapvizDisplay.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AddMapvizDisplay_Request(type):
    """Metaclass of message 'AddMapvizDisplay_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mapviz_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mapviz_interfaces.srv.AddMapvizDisplay_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__add_mapviz_display__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__add_mapviz_display__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__add_mapviz_display__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__add_mapviz_display__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__add_mapviz_display__request

            from marti_common_msgs.msg import KeyValue
            if KeyValue.__class__._TYPE_SUPPORT is None:
                KeyValue.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AddMapvizDisplay_Request(metaclass=Metaclass_AddMapvizDisplay_Request):
    """Message class 'AddMapvizDisplay_Request'."""

    __slots__ = [
        '_name',
        '_type',
        '_draw_order',
        '_visible',
        '_properties',
    ]

    _fields_and_field_types = {
        'name': 'string',
        'type': 'string',
        'draw_order': 'int32',
        'visible': 'boolean',
        'properties': 'sequence<marti_common_msgs/KeyValue>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['marti_common_msgs', 'msg'], 'KeyValue')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.name = kwargs.get('name', str())
        self.type = kwargs.get('type', str())
        self.draw_order = kwargs.get('draw_order', int())
        self.visible = kwargs.get('visible', bool())
        self.properties = kwargs.get('properties', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.name != other.name:
            return False
        if self.type != other.type:
            return False
        if self.draw_order != other.draw_order:
            return False
        if self.visible != other.visible:
            return False
        if self.properties != other.properties:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'name' field must be of type 'str'"
        self._name = value

    @builtins.property  # noqa: A003
    def type(self):  # noqa: A003
        """Message field 'type'."""
        return self._type

    @type.setter  # noqa: A003
    def type(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'type' field must be of type 'str'"
        self._type = value

    @builtins.property
    def draw_order(self):
        """Message field 'draw_order'."""
        return self._draw_order

    @draw_order.setter
    def draw_order(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'draw_order' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'draw_order' field must be an integer in [-2147483648, 2147483647]"
        self._draw_order = value

    @builtins.property
    def visible(self):
        """Message field 'visible'."""
        return self._visible

    @visible.setter
    def visible(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'visible' field must be of type 'bool'"
        self._visible = value

    @builtins.property
    def properties(self):
        """Message field 'properties'."""
        return self._properties

    @properties.setter
    def properties(self, value):
        if __debug__:
            from marti_common_msgs.msg import KeyValue
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, KeyValue) for v in value) and
                 True), \
                "The 'properties' field must be a set or sequence and each value of type 'KeyValue'"
        self._properties = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_AddMapvizDisplay_Response(type):
    """Metaclass of message 'AddMapvizDisplay_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mapviz_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mapviz_interfaces.srv.AddMapvizDisplay_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__add_mapviz_display__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__add_mapviz_display__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__add_mapviz_display__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__add_mapviz_display__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__add_mapviz_display__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AddMapvizDisplay_Response(metaclass=Metaclass_AddMapvizDisplay_Response):
    """Message class 'AddMapvizDisplay_Response'."""

    __slots__ = [
        '_success',
        '_message',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_AddMapvizDisplay(type):
    """Metaclass of service 'AddMapvizDisplay'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mapviz_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mapviz_interfaces.srv.AddMapvizDisplay')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__add_mapviz_display

            from mapviz_interfaces.srv import _add_mapviz_display
            if _add_mapviz_display.Metaclass_AddMapvizDisplay_Request._TYPE_SUPPORT is None:
                _add_mapviz_display.Metaclass_AddMapvizDisplay_Request.__import_type_support__()
            if _add_mapviz_display.Metaclass_AddMapvizDisplay_Response._TYPE_SUPPORT is None:
                _add_mapviz_display.Metaclass_AddMapvizDisplay_Response.__import_type_support__()


class AddMapvizDisplay(metaclass=Metaclass_AddMapvizDisplay):
    from mapviz_interfaces.srv._add_mapviz_display import AddMapvizDisplay_Request as Request
    from mapviz_interfaces.srv._add_mapviz_display import AddMapvizDisplay_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
