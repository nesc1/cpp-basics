cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(hellotests)

message(STATUS "Building ${PROJECT_NAME}...")
add_executable(${PROJECT_NAME}
    ${PROJECT_NAME}.cpp
)
target_link_libraries(${PROJECT_NAME}
    PUBLIC
        GTest::Main
        GTest::GTest
        GMock::GMock
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_BINARY_DIR}
)
# add test
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

# install information
install(TARGETS ${PROJECT_NAME} DESTINATION tests)