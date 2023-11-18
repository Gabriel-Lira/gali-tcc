cmake_minimum_required(VERSION 3.20)

# SRC Lib

set(READER_APP_SRC_NAME ${CMAKE_PROJECT_NAME}_READER_APP_SRC)

add_library(
    ${READER_APP_SRC_NAME}

    ./app/src/app.c

    ./app/src/communication/physical/physical.c

    ./app/src/communication/stack/stack.c
    ./app/src/communication/stack/layer/layer.c
)

target_include_directories(
    ${READER_APP_SRC_NAME}

    PUBLIC
        ./app/include
)

# App Executable

set(READER_APP_EXEC_NAME ${CMAKE_PROJECT_NAME}_READER_APP)

add_executable(
    ${READER_APP_EXEC_NAME}

    main_app_reader.c
)

target_link_libraries(
    ${READER_APP_EXEC_NAME}

    PUBLIC
        # GALI::utils
        ${READER_APP_SRC_NAME}
)

add_custom_target(
    run_app

    COMMAND
        ${READER_APP_EXEC_NAME}

    DEPENDS
        ${READER_APP_EXEC_NAME}

    USES_TERMINAL
)

