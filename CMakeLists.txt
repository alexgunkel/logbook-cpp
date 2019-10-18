cmake_minimum_required (VERSION 3.2)

# set(CMAKE_CXX_STANDARD 17)
set(LOGBOOK_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set(LOGBOOK_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(LOGBOOK_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(LOGBOOK_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(LOGBOOK_VENDOR_DIR ${PROJECT_SOURCE_DIR}/vendor)

include_directories("${LOGBOOK_INCLUDE_DIR}")

add_subdirectory(src)
add_subdirectory(test)



         
