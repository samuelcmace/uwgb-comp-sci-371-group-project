# Specify the minimum version of CMake that is required to build the project.
cmake_minimum_required(VERSION 3.10)
project(bank_application)

# Set the name for the project.
project(bank_application)

# Add all header files to the build configuration so that all of the source files can "see" them as if they were in the
# current directory.
include_directories(lib)

# Set default build type to Debug. This can be overridden by the user by specifying -DCMAKE_BUILD_TYPE=Release when
# running CMake. Also, add the debugging symbols to allow gdb to be used for debugging.
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

set(CMAKE_CXX_STANDARD 17)
set(SOURCES
        src/CSVObject.cpp
        src/Bank.cpp
        src/User.cpp
        src/Manager.cpp
        src/Customer.cpp
        src/BankAccount.cpp
        src/Transaction.cpp
)

# Copy the assets directory from the source directory into whatever the output (or build) directory happens to be...
file(COPY ${CMAKE_SOURCE_DIR}/assets/test_data DESTINATION ${CMAKE_BINARY_DIR}/assets)
file(COPY ${CMAKE_SOURCE_DIR}/assets/users.csv DESTINATION ${CMAKE_BINARY_DIR})

# For each project executable, specify the name of the executable (as it will be after compilation), as well as the
# .cpp files that need to be linked to the project, as well as the .cpp that contains the main function to be executed
# along with the binary.
add_executable(bank_application ${SOURCES} main.cpp)
add_executable(Test_CSVObject ${SOURCES} tests/Test_CSVObject.cpp)

# The add_test command can be used to use the CTest framework. This provides the benefit that the unit tests will be
# marked as such when running CTest.
add_test(NAME Test_CSVObject COMMAND Test_CSVObject)
