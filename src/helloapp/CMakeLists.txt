cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

set(PROJ_MAJOR_VERSION 1)
set(PROJ_MINOR_VERSION 0)
set(PROJ_PATCH_VERSION 0)
set(PROJ_VERSION
    ${PROJ_MAJOR_VERSION}.${PROJ_MINOR_VERSION}.${PROJ_PATCH_VERSION})

project(helloapp VERSION ${PROJ_VERSION} LANGUAGES CXX)

# inform of our project
message(STATUS "Building ${PROJECT_NAME}...")

add_executable(${PROJECT_NAME}
    ${PROJECT_NAME}.cpp
)
# link
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        CONAN_PKG::spdlog)

# install information
install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_BIN_DIR})