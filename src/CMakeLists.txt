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
include_directories(${LOGBOOK_SRC_DIR})

set(HEADER_FILES logbookserver.hpp)
set(SOURCE_FILES main.cpp logbookserver.cpp)

add_executable(logbook ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(logbook bridge udplistener)

install(TARGETS logbook DESTINATION ${LOGBOOK_BIN_DIR})
