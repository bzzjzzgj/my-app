project(my.ui)


add_library(${PROJECT_NAME} STATIC
        # imgui
        src/imgui/imgui.cpp
        src/imgui/imgui_demo.cpp
        src/imgui/imgui_draw.cpp
        src/imgui/imgui_tables.cpp
        src/imgui/imgui_widgets.cpp
        src/imgui/imgui_impl_glfw.cpp
        src/imgui/imgui_impl_opengl3.cpp

        # self
        src/core/ui_manager.cpp
        src/internal/widget_container.cpp
        src/widgets/awidget.cpp
        src/modules/canvas.cpp
        
)


target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/imgui
        ${CMAKE_SOURCE_DIR}/dependencies/glfw/include
)

target_link_libraries(${PROJECT_NAME} PUBLIC
        my.windowing
        my.maths
        my.tools
)