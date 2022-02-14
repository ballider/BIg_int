cmake_minimum_required(VERSION 2.8)

project(CIntN)

set(CIntN_src main.cpp CIntN.cpp func.cpp operators.cpp AutoTest.cpp)
set(CIntN_hdr head.hpp CIntN.hpp CIntN1.hpp CIntN0.hpp AutoTest.hpp)

add_executable(${PROJECT_NAME} ${CIntN_src} ${CIntN_hdr})