cmake_minimum_required(VERSION 3.27.6)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

project(Bank_Management_System_App VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Bank_Management_System_App ./src/main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
