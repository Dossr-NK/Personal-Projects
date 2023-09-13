cmake_minimum_required(VERSION 3.10)
project(Minesweeper VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Minesweeper main.cc game_board.cc game_logic.cc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
