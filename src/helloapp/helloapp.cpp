#include <iostream>
#include <string>

#include <spdlog/spdlog.h>

// main entry point
int main(int argc, char const *argv[])
{
    // change log pattern
    spdlog::set_pattern("[%^%L%$][%M:%S] %v");
    // log something
    spdlog::info("Hello {}!", "World");
    return 0;
}