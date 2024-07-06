cmake_minimum_required(VERSION 3.16)

project(kernel-drivers-test)

set(SOURCES
    buffer_test.c
)

set(HEADERS
    
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
