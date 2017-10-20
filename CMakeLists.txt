cmake_minimum_required(VERSION 3.0.0)

project(qtwt)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

# Trying to find Wt libraries
find_package(Wt REQUIRED)
if(NOT Wt_FOUND)
    message(SEND_ERROR "Failed to find Wt")
    return()
else()
    include_directories(${Wt_INCLUDE_DIRS})
endif()
# Trying to find Boost libraries
find_package(Boost REQUIRED COMPONENTS thread system filesystem)
if(NOT Boost_FOUND)
    message(SEND_ERROR "Failed to find Boost")
    return()
else()
    include_directories(${Boost_INCLUDE_DIRS})
endif()

# Including our configure file in the same directory where binary is
#configure_file(inc/def.h.in ${CMAKE_CURRENT_BINARY_DIR}/def.h)
# Including our directories
include_directories(
    api
    inc
    obj
    )
# Including our .cpp files to project
file(GLOB SRC_LIST
    *.cpp
    api/*.cpp
    inc/*.cpp
    obj/*.cpp
    )
# Creating executable
add_executable(${PROJECT_NAME}.wt ${SRC_LIST})
# Linking libraries
target_link_libraries(${PROJECT_NAME}.wt Qt5::Core ${Wt_HTTP_LIBRARY} ${Wt_LIBRARY}
    ${Wt_DBO_LIBRARY} ${Wt_DBOMYSQL_LIBRARY} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})


