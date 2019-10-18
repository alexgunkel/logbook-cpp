cmake_minimum_required(VERSION 3.2)
project(logbook C CXX)

set(SOURCE_FILES
    websocket.cpp
    ostreamwriter.cpp
)

set(HEADER_FILES ostreamwriter.h websocket.hpp)

add_library(ostreamwriter SHARED STATIC ${SOURCE_FILES} ${HEADER_FILES})

include_directories(ostreamwriter ${LOGBOOK_SRC_DIR}
  ${LOGBOOK_INCLUDE_DIR}
  ${LOGBOOK_VENDOR_DIR}/uWebSockets/src/
  ${LOGBOOK_VENDOR_DIR}/uWebSockets/uSockets/src/)

set_property(TARGET ostreamwriter PROPERTY CXX_STANDARD 17)

target_link_libraries(ostreamwriter bridge)

install(TARGETS ostreamwriter DESTINATION ${LOGBOOK_LIB_DIR})
install(FILES ostreamwriter.h DESTINATION ${LOGBOOK_INCLUDE_DIR})
