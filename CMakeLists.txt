cmake_minimum_required(VERSION 3.25)
project(meow C)

include(GNUInstallDirs)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "Install path prefix" FORCE)
endif()

add_executable(meow main.c)

install(TARGETS meow RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
