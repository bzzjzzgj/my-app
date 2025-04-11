project(my.debug)

add_library(${PROJECT_NAME} STATIC
    src/assertion.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)