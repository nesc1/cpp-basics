# Minimum version is the one shipping with Ubuntu 16.04 LTS
cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project("CPP-BASICS")

# specify if the unit tests are to build
option(BUILD_SRC            "Build the project source" ON)
option(BUILD_TESTS          "Build the unit tests" ON)

# Offer the user the choice of overriding the installation directories
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR
    include
    CACHE PATH "Installation directory for header files")
set(INSTALL_CMAKE_DIR
    "lib/cmake"
    CACHE PATH "Installation directory for CMake files")

set(CONANBUILDINFO_PATH
"${PROJECT_SOURCE_DIR}/conan/gcc"
CACHE
    STRING
    "Location where conanbuildinfo.cmake is located"
)

# ##############################################################################
# Conan:
# ##############################################################################
if(EXISTS ${CONANBUILDINFO_PATH}/conanbuildinfo.cmake)
  include(${CONANBUILDINFO_PATH}/conanbuildinfo.cmake)
  conan_basic_setup(TARGETS)
elseif()
  message(FATAL_ERROR "CONAN targets NOT FOUND!")
endif()


# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# silent some warnings
add_definitions(
    -D_USING_INSTANCE_OVERRIDE
    -D_SCL_SECURE_NO_WARNINGS
    -D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
)
if(WIN32)
    add_definitions(
        -D_WIN32_WINNT=0x0601
        -D_CRT_SECURE_NO_WARNINGS
    )
endif()

if(BUILD_SRC)
    message(STATUS "Build application source...")
    add_subdirectory(src)
endif()
if(BUILD_TESTS)
  message(STATUS "Build test modules...")
  # Note: testing must be enabled at top script level
  enable_testing()
  add_subdirectory(tests)
else()
  message(STATUS "Unit tests will not be built")
endif()
