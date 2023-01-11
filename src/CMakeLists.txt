cmake_minimum_required(VERSION 2.6)
project(spi)
add_executable(spi_test spi_test.cpp W25Q32.cpp)
target_link_libraries(spi_test wiringPi)
