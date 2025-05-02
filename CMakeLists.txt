cmake_minimum_required(VERSION 3.29)
project(Laba8)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)

FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(nlohmann_json)

include_directories("${CMAKE_BINARY_DIR}/_deps/nlohmann_json-src/include")


set(CURL_INCLUDE_DIR "C:/curl-8.13.0_3-win64-mingw/include")
set(CURL_LIBRARY "C:/curl-8.13.0_3-win64-mingw/lib/libcurl.dll.a")

find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIR} include)

add_executable(Laba8 main.cpp
        include/json.hpp)


target_link_libraries(Laba8 CURL::libcurl)
