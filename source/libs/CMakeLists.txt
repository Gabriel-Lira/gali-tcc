# Cmake required
cmake_minimum_required(VERSION 3.21)

# add_subdirectory(utils)

# Lib source
set(LIB_GUI_NAME GALI_IMGUI_LIB)


add_library(
    ${LIB_GUI_NAME} STATIC

    ./imgui/backends/imgui_impl_dx11.cpp
    ./imgui/backends/imgui_impl_win32.cpp

    ./imgui/imgui_demo.cpp
    ./imgui/imgui_draw.cpp
    ./imgui/imgui_tables.cpp
    ./imgui/imgui_widgets.cpp
    ./imgui/imgui.cpp
)

add_library(GALI::imgui ALIAS ${LIB_GUI_NAME})

target_include_directories(
    ${LIB_GUI_NAME}

    PUBLIC
    ./imgui/backends
    ./imgui
)

target_link_libraries(
    ${LIB_GUI_NAME}

    PUBLIC
        #d3d12.lib
        d3d11.lib
        
)

target_compile_features(
    ${LIB_GUI_NAME}

    PUBLIC
    c_std_11
)

target_compile_options(
    ${LIB_GUI_NAME}

    PRIVATE
    $<$<C_COMPILER_ID:MSVC>:/W4>
)

