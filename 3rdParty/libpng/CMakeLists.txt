include(functions/FetchContent_MakeAvailableExcludeFromAll)

if(NOT DISABLE_LTO)
  # Force CMake to raise an error if INTERPROCEDURAL_OPTIMIZATION
  # is enabled and compiler does not support IPO
  set(CMAKE_POLICY_DEFAULT_CMP0069 NEW)
endif()

if(DEVILUTIONX_STATIC_LIBPNG)
  set(PNG_LIBRARY png_static)
  set(PNG_STATIC ON)
  set(PNG_SHARED OFF)
else()
  set(PNG_LIBRARY png)
  set(PNG_STATIC OFF)
  set(PNG_SHARED ON)
endif()
set(PNG_TESTS OFF)
set(PNG_EXECUTABLES OFF)
set(SKIP_INSTALL_ALL ON)

if(APPLE AND "${CMAKE_OSX_ARCHITECTURES}" STREQUAL "arm64")
  set(PNG_ARM_NEON "on" CACHE STRING "" FORCE)
endif()

include(FetchContent)
FetchContent_Declare(
  libpng
  GIT_REPOSITORY https://github.com/pnggroup/libpng.git
  GIT_TAG        ed217e3e601d8e462f7fd1e04bed43ac42212429 # v1.6.43
)
FetchContent_MakeAvailableExcludeFromAll(libpng)

target_include_directories(${PNG_LIBRARY} INTERFACE
  $<BUILD_INTERFACE:${libpng_SOURCE_DIR}>
  $<BUILD_INTERFACE:${libpng_BINARY_DIR}>)

add_library(PNG::PNG ALIAS ${PNG_LIBRARY})
