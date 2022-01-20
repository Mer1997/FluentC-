cmake_minimum_required(VERSION 3.8.12)
project(FluentCpp)
 
#设定编译参数
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
 
# aux_source_directory(${CMAKE_SOURCE_DIR} DIR)
add_executable(fluentcpp 
  ${CMAKE_SOURCE_DIR}/main.cc
  ${CMAKE_SOURCE_DIR}/Frige.cc)
 
#target_link_libraries(moderncpp pthread stdc++fs)
#就是g++ 编译选项中-l后的内容，不要有多余空格

