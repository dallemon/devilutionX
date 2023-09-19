SET(MINGW_CROSS TRUE)

SET(CROSS_PREFIX "/usr" CACHE STRING "crosstool-NG prefix")

SET(CMAKE_SYSTEM_NAME Windows)

# workaround
list(APPEND CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES "${CROSS_PREFIX}/i686-w64-mingw32/include")

list(PREPEND CMAKE_C_STANDARD_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/mingw9x/include")
list(PREPEND CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/mingw9x/include")

SET(CMAKE_C_COMPILER   "i686-w64-mingw32-gcc")
SET(CMAKE_CXX_COMPILER "i686-w64-mingw32-g++")
set(CMAKE_RC_COMPILER "i686-w64-mingw32-windres")
set(PKG_CONFIG_EXECUTABLE "${CROSS_PREFIX}/bin/i686-w64-mingw32-pkg-config" CACHE STRING "Path to pkg-config")

SET(CMAKE_FIND_ROOT_PATH  "${CROSS_PREFIX}/i686-w64-mingw32" "${CROSS_PREFIX}/i686-w64-mingw32/i686-w64-mingw32")

SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(WIN32_INSTALL_DLLS "${CROSS_PREFIX}/i686-w64-mingw32/bin/SDL.dll")
