cmake_minimum_required(VERSION 3.13)
project(llvmObfuscation C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Using LLVM ${LLVM_PACKAGE_VERSION} (dylib at ${LLVM_LIBRARY_DIRS})")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_library(ObfuscateZero MODULE ObfuscateZero/ObfuscateZero.cpp)
set_target_properties(ObfuscateZero PROPERTIES PREFIX "" OUTPUT_NAME "ObfuscateZero")

target_compile_options(ObfuscateZero PRIVATE -fno-exceptions -fno-rtti)

target_link_libraries(ObfuscateZero PRIVATE LLVM)
