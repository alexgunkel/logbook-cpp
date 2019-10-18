project(logbook)

# The version number.
set (Logbook_VERSION_MAJOR 1)
set (Logbook_VERSION_MINOR 0)

configure_file (
  "${LOGBOOK_SRC_DIR}/LogbookConfig.h.in"
  "${LOGBOOK_SRC_DIR}/LogbookConfig.h"
)

add_subdirectory(bridge)
add_subdirectory(crows_nest)
add_subdirectory(books)

include_directories(${LOGBOOK_SRC_DIR}
  ${LOGBOOK_VENDOR_DIR}/uWebSockets/src/
  ${LOGBOOK_VENDOR_DIR}/uWebSockets/uSockets/src/)
link_directories(${LOGBOOK_VENDOR_DIR}/lib)


set(HEADER_FILES logbookserver.hpp)
set(SOURCE_FILES main.cpp logbookserver.cpp)

find_package(ZLIB)

add_executable(logbook ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(logbook bridge udplistener ostreamwriter ${ZLIB_LIBRARIES} ${LOGBOOK_VENDOR_DIR}/lib/uSockets.a)
set_property(TARGET logbook PROPERTY CXX_STANDARD 17)

install(TARGETS logbook DESTINATION ${LOGBOOK_BIN_DIR})
