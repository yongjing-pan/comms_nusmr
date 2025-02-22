# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_multires_image_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED multires_image_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(multires_image_FOUND FALSE)
  elseif(NOT multires_image_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(multires_image_FOUND FALSE)
  endif()
  return()
endif()
set(_multires_image_CONFIG_INCLUDED TRUE)

# output package information
if(NOT multires_image_FIND_QUIETLY)
  message(STATUS "Found multires_image: 2.4.5 (${multires_image_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'multires_image' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${multires_image_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(multires_image_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_dependencies-extras.cmake;ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake")
foreach(_extra ${_extras})
  include("${multires_image_DIR}/${_extra}")
endforeach()
