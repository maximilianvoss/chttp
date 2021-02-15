cmake_minimum_required(VERSION 3.0)
project(chttp C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

# required packages
find_package(CURL REQUIRED)
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(CLOGGER REQUIRED)

# debug handling for build
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    set(CMAKE_VERBOSE_MAKEFILE on)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")
    set(CMAKE_INSTALL_PREFIX /usr/local)
else ()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O3")
endif ()

if (NOT nofpic)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O3 -fPIC")
endif ()

# Header file directories
set(INCLUDE_DIRECTORIES
        ${INCLUDE_DIRECTORIES}
        ${CURL_INCLUDE_DIRS}
        ${OPENSSL_INCLUDE_DIR}
        ${CLOGGER_INCLUDE_DIR}
        )
include_directories(${INCLUDE_DIRECTORIES})

# ROM Library Sources
set(SOURCES_LIBRARY
        chttp.c
        chttp.h
        )

if (NOT TARGET chttp)
    add_library(chttp ${SOURCES_LIBRARY})
    target_link_libraries(chttp ${OPENSSL_LIBRARIES} ${CURL_LIBRARIES})

    # Install
    install(TARGETS chttp DESTINATION lib)
    install(FILES chttp.h DESTINATION include)
endif ()

