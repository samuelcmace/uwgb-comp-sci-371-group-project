cmake_minimum_required(VERSION 3.10)
project(bank_application)

include_directories(lib)

set(CMAKE_CXX_STANDARD 11)
set(SOURCES
    src/CSVObject.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
