project(my.core)

add_library(${PROJECT_NAME} STATIC
        src/global/service_locator.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)