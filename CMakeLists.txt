cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_SHARED_LIBS "Build libraries as DLLs" FALSE)
find_package(nlohmann_json REQUIRED)

list(TRANSFORM CMAKE_PREFIX_PATH APPEND "/include"
     OUTPUT_VARIABLE CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES)
set(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES "${CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES}")

set(CMAKE_FIND_FRAMEWORK NEVER)
set(CMAKE_FIND_APPBUNDLE NEVER)

set(CMAKE_FIND_USE_CMAKE_SYSTEM_PATH FALSE)
set(CMAKE_FIND_USE_SYSTEM_ENVIRONMENT_PATH FALSE)

set(CMAKE_OSX_ARCHITECTURES "x86_64")

project(MMQ)

set(SOURCES src/main.cpp src/mmq.cpp include/mmq.hpp)
add_executable(MMQ ${SOURCES})

target_include_directories(MMQ PUBLIC
                           "include"
                           )

target_link_libraries(MMQ nlohmann_json::nlohmann_json)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")