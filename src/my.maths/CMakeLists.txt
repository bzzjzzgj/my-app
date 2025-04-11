project(my.maths)

add_library(${PROJECT_NAME} STATIC
    src/f_vector2.cpp
    src/f_vector3.cpp
    src/f_vector4.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)