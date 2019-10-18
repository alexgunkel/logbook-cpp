cmake_minimum_required(VERSION 3.2)
project(logbook_tests)
set(LOGBOOK_TEST_BIN_DIR ${PROJECT_SOURCE_DIR})

enable_testing()

add_subdirectory(lib/googletest)

include_directories(${LOGBOOK_SRC_DIR}/)
include_directories(${LOGBOOK_INCLUDE_DIR}/)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

set(TEST_SOURCES
  main.cpp
  src/message_test.cpp
  src/bookshelf_test.cpp
  src/captainsdesk_test.cpp
  src/ostreamwriter_test.cpp
  src/portauthority_test.cpp)

add_executable(logbook_test ${TEST_SOURCES})
target_link_libraries(logbook_test gtest gmock bridge)
