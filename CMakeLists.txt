cmake_minimum_required(VERSION 3.22)
project(STANDARTS_CONTAINERS)

file(GLOB SOURCE
        "source/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCE})
