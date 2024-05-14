include(functions/FetchContent_MakeAvailableExcludeFromAll)

set(CMAKE_POLICY_DEFAULT_CMP0048 NEW)

include(FetchContent)
FetchContent_Declare(zlib
    URL https://github.com/madler/zlib/releases/download/v1.3.1/zlib-1.3.1.tar.gz
    URL_HASH SHA256=9a93b2b7dfdac77ceba5a558a580e74667dd6fede4585b91eefb60f03b72df23
)
FetchContent_MakeAvailableExcludeFromAll(zlib)

if(DEVILUTIONX_STATIC_ZLIB)
  add_library(ZLIB::ZLIB ALIAS zlibstatic)
  target_include_directories(zlibstatic INTERFACE ${zlib_BINARY_DIR} ${zlib_SOURCE_DIR})
else()
  add_library(ZLIB::ZLIB ALIAS zlib)
  target_include_directories(zlib INTERFACE ${zlib_BINARY_DIR} ${zlib_SOURCE_DIR})
endif()

# 1. Set the variables that are usually set by FindZLIB.cmake.
# 2. Add the module that stubs out `find_package(ZLIB ...)` calls.
set(ZLIB_FOUND ON PARENT_SCOPE)
set(ZLIB_LIBRARY ZLIB::ZLIB PARENT_SCOPE)
set(ZLIB_LIBRARIES ZLIB::ZLIB PARENT_SCOPE)
set(ZLIB_INCLUDE_DIR ${zlib_SOURCE_DIR} ${zlib_BINARY_DIR} PARENT_SCOPE)
set(ZLIB_INCLUDE_DIRS ${zlib_SOURCE_DIR} ${zlib_BINARY_DIR} PARENT_SCOPE)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_LIST_DIR}/CMake" PARENT_SCOPE)
