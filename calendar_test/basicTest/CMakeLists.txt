set(gtest_SOURCE_DIR ../lib/gtest-1.7.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(runBCT basicTest.cpp)

target_link_libraries(runBCT gtest gtest_main)
target_link_libraries(runBCT calendarAndDate)