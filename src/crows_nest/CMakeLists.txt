cmake_minimum_required(VERSION 3.2)
project(logbook C CXX)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)

find_package(Boost 1.70.00 REQUIRED COMPONENTS thread system)
message(STATUS "Boost version: ${Boost_VERSION}")

find_package (Threads)

set(HEADERS udplistener.hpp)
set(SOURCE_FILES udplistener.cpp)

include_directories(${LOGBOOK_SRC_DIR})

add_library(udplistener SHARED STATIC ${SOURCE_FILES} ${HEADERS})
target_link_libraries(udplistener ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
