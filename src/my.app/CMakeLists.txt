project(my.app)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/core/application.cpp
    src/core/context.cpp
    src/core/editor.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    my.windowing
    my.ui  
)