cmake_minimum_required(VERSION 3.20)

set(EMULATOR_EXEC_NAME ${CMAKE_PROJECT_NAME}_EMULATOR_APP)

if(NOT CMAKE_CROSSCOMPILING)
    add_executable(
        ${EMULATOR_EXEC_NAME}

        main_emulator.cpp

        ./application/impl/com_ports.cpp
        ./application/impl/imgui_window.cpp
        ./application/impl/emulator_window.cpp
    )

    target_include_directories(
        ${EMULATOR_EXEC_NAME}

        PUBLIC
            ./application/include
    )

    target_link_libraries(
        ${EMULATOR_EXEC_NAME}

        PUBLIC
            # GALI::utils
            GALI_IMGUI_LIB
            serial_SRCS
            
    )

    target_compile_features(
        ${EMULATOR_EXEC_NAME}

        PUBLIC
            c_std_11
            cxx_std_17
    )

    add_custom_target(
        emulator_run

        COMMAND
            ${EMULATOR_EXEC_NAME}

        DEPENDS
            ${EMULATOR_EXEC_NAME}

        USES_TERMINAL
    )
endif()