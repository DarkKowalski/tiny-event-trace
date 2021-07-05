cmake_minimum_required(VERSION 3.20)
project(tiny_event_trace VERSION 0.0.1 DESCRIPTION "Profile your C program with chrome://tracting")
set(PROJECT_BINARY_DIR ./build)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -O3 -fno-fast-math -ggdb3")

set(PUBLIC_INCLUDE_DIRECTORIES include/)
file(GLOB_RECURSE RELEASE_PUBLIC_HEADERS "include/*.h")

aux_source_directory(./src DIR_SRCS)

add_library(${PROJECT_NAME} SHARED ${DIR_SRCS} ${RELEASE_PUBLIC_HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${PUBLIC_INCLUDE_DIRECTORIES})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    PUBLIC_HEADER "${RELEASE_PUBLIC_HEADERS}"
)

INSTALL(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION lib/${PROJECT_NAME}
        PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
)

add_subdirectory(test)
enable_testing()
add_test(test_simple ./test/test_simple.out)
