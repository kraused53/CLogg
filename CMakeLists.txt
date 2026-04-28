cmake_minimum_required( VERSION 3.20 )

project( CLOGG VERSION 0.1.0 LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin )

# Option to build examples (OFF by default for FetchContent users)
option( CLOGG_BUILD_EXAMPLES "Build clogg examples" ON )

add_library(
  CLogg STATIC
    src/CLogg.cpp
    src/utils.cpp
)

target_include_directories(
  CLogg
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
)

# Give it a namespace
add_library( clogg::clogg ALIAS clogg )

# Need C++20 for <format>
target_compile_features(CLogg PUBLIC cxx_std_20)

if (CLOGG_BUILD_EXAMPLES)
    add_executable(
      clogg_testing
        example/clogg_testing.cpp
    )

    target_link_libraries(
      clogg_testing
        PRIVATE 
        CLogg
    )
endif()