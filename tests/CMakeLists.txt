# Minimum version is the one shipping with Ubuntu 16.04 LTS
cmake_minimum_required(VERSION 3.0.2)

# find packages
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)

add_subdirectory(hellotests)