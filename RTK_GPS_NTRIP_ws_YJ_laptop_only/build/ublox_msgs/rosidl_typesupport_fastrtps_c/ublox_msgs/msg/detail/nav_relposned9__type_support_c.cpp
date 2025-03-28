// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ublox_msgs:msg/NavRELPOSNED9.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_relposned9__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ublox_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ublox_msgs/msg/detail/nav_relposned9__struct.h"
#include "ublox_msgs/msg/detail/nav_relposned9__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _NavRELPOSNED9__ros_msg_type = ublox_msgs__msg__NavRELPOSNED9;

static bool _NavRELPOSNED9__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _NavRELPOSNED9__ros_msg_type * ros_message = static_cast<const _NavRELPOSNED9__ros_msg_type *>(untyped_ros_message);
  // Field name: version
  {
    cdr << ros_message->version;
  }

  // Field name: reserved1
  {
    cdr << ros_message->reserved1;
  }

  // Field name: ref_station_id
  {
    cdr << ros_message->ref_station_id;
  }

  // Field name: i_tow
  {
    cdr << ros_message->i_tow;
  }

  // Field name: rel_pos_n
  {
    cdr << ros_message->rel_pos_n;
  }

  // Field name: rel_pos_e
  {
    cdr << ros_message->rel_pos_e;
  }

  // Field name: rel_pos_d
  {
    cdr << ros_message->rel_pos_d;
  }

  // Field name: rel_pos_length
  {
    cdr << ros_message->rel_pos_length;
  }

  // Field name: rel_pos_heading
  {
    cdr << ros_message->rel_pos_heading;
  }

  // Field name: reserved2
  {
    size_t size = 4;
    auto array_ptr = ros_message->reserved2;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: rel_pos_hpn
  {
    cdr << ros_message->rel_pos_hpn;
  }

  // Field name: rel_pos_hpe
  {
    cdr << ros_message->rel_pos_hpe;
  }

  // Field name: rel_pos_hpd
  {
    cdr << ros_message->rel_pos_hpd;
  }

  // Field name: rel_pos_hp_length
  {
    cdr << ros_message->rel_pos_hp_length;
  }

  // Field name: acc_n
  {
    cdr << ros_message->acc_n;
  }

  // Field name: acc_e
  {
    cdr << ros_message->acc_e;
  }

  // Field name: acc_d
  {
    cdr << ros_message->acc_d;
  }

  // Field name: acc_length
  {
    cdr << ros_message->acc_length;
  }

  // Field name: acc_heading
  {
    cdr << ros_message->acc_heading;
  }

  // Field name: reserved3
  {
    size_t size = 4;
    auto array_ptr = ros_message->reserved3;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: flags
  {
    cdr << ros_message->flags;
  }

  return true;
}

static bool _NavRELPOSNED9__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _NavRELPOSNED9__ros_msg_type * ros_message = static_cast<_NavRELPOSNED9__ros_msg_type *>(untyped_ros_message);
  // Field name: version
  {
    cdr >> ros_message->version;
  }

  // Field name: reserved1
  {
    cdr >> ros_message->reserved1;
  }

  // Field name: ref_station_id
  {
    cdr >> ros_message->ref_station_id;
  }

  // Field name: i_tow
  {
    cdr >> ros_message->i_tow;
  }

  // Field name: rel_pos_n
  {
    cdr >> ros_message->rel_pos_n;
  }

  // Field name: rel_pos_e
  {
    cdr >> ros_message->rel_pos_e;
  }

  // Field name: rel_pos_d
  {
    cdr >> ros_message->rel_pos_d;
  }

  // Field name: rel_pos_length
  {
    cdr >> ros_message->rel_pos_length;
  }

  // Field name: rel_pos_heading
  {
    cdr >> ros_message->rel_pos_heading;
  }

  // Field name: reserved2
  {
    size_t size = 4;
    auto array_ptr = ros_message->reserved2;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: rel_pos_hpn
  {
    cdr >> ros_message->rel_pos_hpn;
  }

  // Field name: rel_pos_hpe
  {
    cdr >> ros_message->rel_pos_hpe;
  }

  // Field name: rel_pos_hpd
  {
    cdr >> ros_message->rel_pos_hpd;
  }

  // Field name: rel_pos_hp_length
  {
    cdr >> ros_message->rel_pos_hp_length;
  }

  // Field name: acc_n
  {
    cdr >> ros_message->acc_n;
  }

  // Field name: acc_e
  {
    cdr >> ros_message->acc_e;
  }

  // Field name: acc_d
  {
    cdr >> ros_message->acc_d;
  }

  // Field name: acc_length
  {
    cdr >> ros_message->acc_length;
  }

  // Field name: acc_heading
  {
    cdr >> ros_message->acc_heading;
  }

  // Field name: reserved3
  {
    size_t size = 4;
    auto array_ptr = ros_message->reserved3;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: flags
  {
    cdr >> ros_message->flags;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t get_serialized_size_ublox_msgs__msg__NavRELPOSNED9(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NavRELPOSNED9__ros_msg_type * ros_message = static_cast<const _NavRELPOSNED9__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name version
  {
    size_t item_size = sizeof(ros_message->version);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved1
  {
    size_t item_size = sizeof(ros_message->reserved1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ref_station_id
  {
    size_t item_size = sizeof(ros_message->ref_station_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name i_tow
  {
    size_t item_size = sizeof(ros_message->i_tow);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rel_pos_n
  {
    size_t item_size = sizeof(ros_message->rel_pos_n);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rel_pos_e
  {
    size_t item_size = sizeof(ros_message->rel_pos_e);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rel_pos_d
  {
    size_t item_size = sizeof(ros_message->rel_pos_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rel_pos_length
  {
    size_t item_size = sizeof(ros_message->rel_pos_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rel_pos_heading
  {
    size_t item_size = sizeof(ros_message->rel_pos_heading);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved2
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->reserved2;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rel_pos_hpn
  {
    size_t item_size = sizeof(ros_message->rel_pos_hpn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rel_pos_hpe
  {
    size_t item_size = sizeof(ros_message->rel_pos_hpe);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rel_pos_hpd
  {
    size_t item_size = sizeof(ros_message->rel_pos_hpd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rel_pos_hp_length
  {
    size_t item_size = sizeof(ros_message->rel_pos_hp_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name acc_n
  {
    size_t item_size = sizeof(ros_message->acc_n);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name acc_e
  {
    size_t item_size = sizeof(ros_message->acc_e);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name acc_d
  {
    size_t item_size = sizeof(ros_message->acc_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name acc_length
  {
    size_t item_size = sizeof(ros_message->acc_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name acc_heading
  {
    size_t item_size = sizeof(ros_message->acc_heading);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reserved3
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->reserved3;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name flags
  {
    size_t item_size = sizeof(ros_message->flags);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _NavRELPOSNED9__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ublox_msgs__msg__NavRELPOSNED9(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ublox_msgs
size_t max_serialized_size_ublox_msgs__msg__NavRELPOSNED9(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: version
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reserved1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: ref_station_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: i_tow
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rel_pos_n
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rel_pos_e
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rel_pos_d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rel_pos_length
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: rel_pos_heading
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: reserved2
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: rel_pos_hpn
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: rel_pos_hpe
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: rel_pos_hpd
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: rel_pos_hp_length
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: acc_n
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: acc_e
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: acc_d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: acc_length
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: acc_heading
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: reserved3
  {
    size_t array_size = 4;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: flags
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ublox_msgs__msg__NavRELPOSNED9;
    is_plain =
      (
      offsetof(DataType, flags) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _NavRELPOSNED9__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ublox_msgs__msg__NavRELPOSNED9(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_NavRELPOSNED9 = {
  "ublox_msgs::msg",
  "NavRELPOSNED9",
  _NavRELPOSNED9__cdr_serialize,
  _NavRELPOSNED9__cdr_deserialize,
  _NavRELPOSNED9__get_serialized_size,
  _NavRELPOSNED9__max_serialized_size
};

static rosidl_message_type_support_t _NavRELPOSNED9__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_NavRELPOSNED9,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ublox_msgs, msg, NavRELPOSNED9)() {
  return &_NavRELPOSNED9__type_support;
}

#if defined(__cplusplus)
}
#endif
