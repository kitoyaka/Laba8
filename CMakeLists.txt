cmake_minimum_required(VERSION 3.29)
project(Laba8)

set(CMAKE_CXX_STANDARD 20)

set(CURL_INCLUDE_DIR "C:/curl-8.13.0_3-win64-mingw/include")
set(CURL_LIBRARY "C:/curl-8.13.0_3-win64-mingw/lib/libcurl.a")

find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIR} include)

add_executable(Laba8 main.cpp)

target_link_libraries(Laba8 ${CURL_LIBRARY})