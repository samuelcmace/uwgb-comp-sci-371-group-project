cmake_minimum_required(VERSION 3.10)
project(bank_application)

include_directories(lib)

set(CMAKE_CXX_STANDARD 17)
enable_testing()

set(SOURCES
    src/CSVObject.cpp
)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)
add_executable(CSVLoadTest ${SOURCES} tests/UnitTests.cpp)

add_test(NAME CSVLoadTest COMMAND CSVLoadTest)
