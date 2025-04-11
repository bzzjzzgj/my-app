project(my.tools)

# add_library(${PROJECT_NAME} INTERFACE)

# target_include_directories(${PROJECT_NAME} INTERFACE 
#     ${PROJECT_SOURCE_DIR}/
#     ${PROJECT_SOURCE_DIR}/eventing
# )

add_library(${PROJECT_NAME} STATIC
    src/time/clock.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)