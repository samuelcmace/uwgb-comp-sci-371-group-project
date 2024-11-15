cmake_minimum_required(VERSION 3.10)
project(foobar)

include_directories(lib)

set(SOURCES
    src/ExampleClass.cpp
    main.cpp
)

add_executable(main ${SOURCES})
