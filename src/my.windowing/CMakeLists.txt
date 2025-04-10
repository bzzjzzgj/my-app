project(my.windowing)

add_library(${PROJECT_NAME} STATIC
        src/window.cpp
        src/context/device.cpp
)

target_include_directories(${PROJECT_NAME}
        PUBLIC include
        ${CMAKE_SOURCE_DIR}/dependencies/glfw/include
        ${CMAKE_SOURCE_DIR}/dependencies/stb
)

target_link_libraries(${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/dependencies/glfw/lib/libglfw3.a
        opengl32
)