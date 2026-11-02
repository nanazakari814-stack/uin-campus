cmake_minimum_required(VERSION 3.15)
project(uincampus cxx)
set(CMAKE_CXX_STANDARD 17)
Set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(uincampus_lib
    src/version.cpp
    include/uincampus/version/hpp
)
target_include_directories(uincampus_lib PUBLIC include)
add_executable(uincampus_app app/main/cpp)
target_link_libraries(uincampus_app PRIVATE uincampus_lib)
