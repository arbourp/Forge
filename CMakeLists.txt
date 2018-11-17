cmake_minimum_required(VERSION 3.9.2)

project(
    Forge
    
    VERSION 0.0.0
    LANGUAGES C CXX
)

include(cmake/CompilerConfiguration.cmake)

add_subdirectory(extern)
add_subdirectory(source)
