cmake_minimum_required(VERSION 3.15)

project(OptionsPricingProject)

# Add this block to control the MSVC Runtime library and match QuantLib's
if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

find_package(QuantLib CONFIG REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE QuantLib::QuantLib)