cmake_minimum_required(VERSION 3.3)
project(cal0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(cxxtest)
include_directories(calendarAndDate)
set(SOURCE_FILES tests.cpp cal_cxxTest.cpp calendarAndDate/date.cpp calendarAndDate/date.hpp calendarAndDate/julian.cpp calendarAndDate/julian.hpp calendarAndDate/gregorian.cpp calendarAndDate/gregorian.hpp calendarAndDate/calendar.hpp calendarAndDate/kattistime.cpp calendarAndDate/kattistime.h)
add_executable(cal0 ${SOURCE_FILES})