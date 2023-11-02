cmake_minimum_required(VERSION 3.20)

set(READER_APP_EXEC_NAME ${CMAKE_PROJECT_NAME}_READER_APP)

add_executable(
    ${READER_APP_EXEC_NAME}

    main_app_reader.c
)

add_custom_target(
    run_app

    COMMAND
        ${READER_APP_EXEC_NAME}

    DEPENDS
        ${READER_APP_EXEC_NAME}

    USES_TERMINAL
)

