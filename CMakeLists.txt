cmake_minimum_required(VERSION 3.5)
project(foobar)

include_directories(lib)

set(SOURCES
    src/ExampleClass.cpp
    main.cpp
)

add_executable(main ${SOURCES})
