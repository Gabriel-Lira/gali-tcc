cmake_minimum_required(VERSION 3.20)

set(EMULATOR_EXEC_NAME ${CMAKE_PROJECT_NAME}_EMULATOR_APP)

add_executable(
    ${EMULATOR_EXEC_NAME}

    main_emulator.cpp

    ./src/emulator_window.cpp
)

target_include_directories(
    ${EMULATOR_EXEC_NAME}

    PUBLIC
        ./include
)

target_link_libraries(
    ${EMULATOR_EXEC_NAME}

    PUBLIC
        # GALI::utils
        GALI_IMGUI_LIB
        
)

add_custom_target(
    emulator_run

    COMMAND
        ${EMULATOR_EXEC_NAME}

    DEPENDS
        ${EMULATOR_EXEC_NAME}

    USES_TERMINAL
)

