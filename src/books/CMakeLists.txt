cmake_minimum_required(VERSION 3.2)
project(logbook C CXX)

set(SOURCE_FILES
    ostreamwriter.h
    ostreamwriter.cpp
)

add_library(ostreamwriter SHARED STATIC ${SOURCE_FILES})
target_link_libraries(ostreamwriter bridge entry)

install(TARGETS ostreamwriter DESTINATION ${LOGBOOK_LIB_DIR})
install(FILES ostreamwriter.h DESTINATION ${LOGBOOK_INCLUDE_DIR})
