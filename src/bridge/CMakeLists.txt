cmake_minimum_required(VERSION 3.2)
project(logbook C CXX)

find_package(Boost 1.70.00)
message(STATUS "Boost version: ${Boost_VERSION}")

set(HEADERS bridge.hpp portauthority.hpp)
set(SOURCE_FILES message.cpp bookshelf.cpp captainsdesk.cpp portauthority.cpp)

add_library(bridge SHARED STATIC ${SOURCE_FILES} ${HEADERS})

install(TARGETS bridge DESTINATION ${LOGBOOK_LIB_DIR})
install(FILES bridge.hpp DESTINATION ${LOGBOOK_INCLUDE_DIR})
