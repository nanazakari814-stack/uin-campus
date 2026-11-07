cmake_minimum_required(VERSION 3.20)
project(uin-campus)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_library(uincampus_core
  src/version.cpp
  src/regles.cpp
  src/saisie.cpp
)
target_include_directories(uincampus_core PUBLIC             
${CMAKE_CURRENT_SOURCE_DIR}/include
${CMAKE_CURRENT_SOURCE_DIR}/src
)
add_executable(uin-campus app/main.cpp)
target_link_libraries(uin-campus PRIVATE uincampus_core)
