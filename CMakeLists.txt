# Specify the minimum version of CMake that is required to build the project.
cmake_minimum_required(VERSION 3.10)
project(bank_application)

# Set the name for the project.
project(bank_application)

# Add all header files to the build configuration so that all of the source files can "see" them as if they were in the
# current directory.
include_directories(lib)

# Require C++17 for building this project.
set(CMAKE_CXX_STANDARD 17)

# Enable unit testing for the CMake project.
enable_testing()

# Create a variable called SOURCES that contains all of the .cpp files (other than ones with a main function) that will
# need to be linked to all executables.
set(SOURCES
    src/CSVObject.cpp
    src/BankAccount.cpp
    src/UserManager.cpp
    src/User.cpp
    src/Customer.cpp
    src/Employee.cpp
    src/Transaction.cpp
)

# Copy the assets directory from the source directory into whatever the output (or build) directory happens to be...
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})

# For each project executable, specify the name of the executable (as it will be after compilation), as well as the
# .cpp files that need to be linked to the project, as well as the .cpp that contains the main function to be executed
# along with the binary.
add_executable(bank_application ${SOURCES} main.cpp)
add_executable(Test_CSVObject ${SOURCES} tests/Test_CSVObject.cpp)
add_executable(Test_UserManager ${SOURCES} tests/Test_UserManager.cpp)

# The add_test command can be used to use the CTest framework. This provides the benefit that the unit tests will be
# marked as such when running CTest.
add_test(NAME Test_CSVObject COMMAND Test_CSVObject)
add_test(NAME Test_UserManager COMMAND Test_UserManager)
