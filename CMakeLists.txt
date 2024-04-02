cmake_minimum_required(VERSION 3.22)
project(STANDARTS_CONTAINERS)

set(TESTS ON)

include_directories("header")

file(GLOB SOURCE
        "source/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCE})

if(TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    add_library(${PROJECT_NAME}_lib ${SOURCE})
    include_directories("tests")
    file(GLOB TEST_SOURCE
            "test/*.cpp"
    )
    add_executable(${PROJECT_NAME}_tests ${TEST_SOURCE})
    target_link_libraries(${PROJECT_NAME}_tests -lgtest -lgmock)
endif()