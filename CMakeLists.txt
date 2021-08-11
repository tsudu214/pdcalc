cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(pdCalc LANGUAGES CXX)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_SUPPRESS_REGENERATION true)

if("${CMAKE_GENERATOR}" MATCHES "(Win64|IA64)")
  set(PA_x64_postfix ".x64")
endif()

add_compile_options(/wd4819)
add_link_options(/ignore:4099)

add_subdirectory(src)

