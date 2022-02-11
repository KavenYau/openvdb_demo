cmake_minimum_required(VERSION 3.5)
project(openvdb_demo)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

find_package(OpenVDB REQUIRED)
find_package(TBB REQUIRED)
find_library(HALF Half)


include_directories(
    ${OpenVDB_INCLUDE_DIR}
    ${TBB_INCLUDE_DIRS}
)

add_executable(openvdb_demo main.cpp)

target_link_libraries(openvdb_demo
  ${OpenVDB_LIBRARIES}
  ${TBB_LIBRARIES}
  ${HALF}
)
