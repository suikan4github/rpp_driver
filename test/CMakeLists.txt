# To use FetchContent, we need CMake 3.14 or newer. 
cmake_minimum_required(VERSION 3.14)



file(GLOB SOURCES CMAKE_CONFIGURE_DEPENDS "./*.cpp")

# Add the executable for the testcase which is using googletest
add_executable(${PROJECT_NAME} ${SOURCES})

# Remove coverage artifacts before running tests to avoid false positives
# This will prevent the error of the coverage report. 
# On the other hande, this build cannot accumulate coverage data across 
# multiple runs, but it is a tradeoff to avoid the error.
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/reset_coverage.cmake" [=[
file(GLOB_RECURSE coverage_artifacts
         "${PROJECT_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}.dir/*.gcda"
         "${PROJECT_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}.dir/*.gcno")
if(coverage_artifacts)
    file(REMOVE ${coverage_artifacts})
endif()
]=])

add_custom_target(reset_coverage
                                    COMMAND ${CMAKE_COMMAND}
                                                    -DPROJECT_BINARY_DIR=${CMAKE_CURRENT_BINARY_DIR}
                                                    -DPROJECT_NAME=${PROJECT_NAME}
                                                    -P "${CMAKE_CURRENT_BINARY_DIR}/reset_coverage.cmake"
                                    VERBATIM)

add_dependencies(${PROJECT_NAME} reset_coverage)

    # Add the library under test.
    target_link_libraries(${PROJECT_NAME}  
                            GTest::gmock_main
                            rpp_driver  
                            )
    target_link_options(${PROJECT_NAME}
                            PRIVATE --coverage)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

