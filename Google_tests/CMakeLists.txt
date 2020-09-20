#- # 'Google_test' is the subproject name
#- project(Google_tests)
#- 
#- # 'lib' is the folder with Google Test sources
#- include_directories(googletest/include googletest)
#- 
#- # 'Google_Tests_run' is the target name
#- # 'test1.cpp tests2.cpp' are source files with tests
#- # add_executable(Google_Tests_run test1.cpp tests2.cpp)
#- target_link_libraries(Google_Tests_run gtest gtest_main)

add_subdirectory(googletest)
