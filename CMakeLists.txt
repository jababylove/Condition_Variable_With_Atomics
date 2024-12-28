cmake_minimum_required(VERSION 3.16)

project(Condition_Variable_With_Atomics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Condition_Variable_With_Atomics main.cpp)

include(GNUInstallDirs)
install(TARGETS Condition_Variable_With_Atomics
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
