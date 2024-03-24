cmake_minimum_required(VERSION 3.20)

# SRC Lib
set(READER_APP_SRC_NAME ${CMAKE_PROJECT_NAME}_READER_APP_SRC)

add_library(
    ${READER_APP_SRC_NAME}

    ./impl/communication/physical/physical.c

    ./impl/communication/stack/layer/layer.c
    ./impl/communication/stack/stack.c
    
    ./impl/tasks/fsm/fsm.c
    ./impl/tasks/types/task_periodic.c
    ./impl/tasks/queue.c
    ./impl/tasks/task_manager.c
    ./impl/tasks/task_scheduler.c
    ./impl/tasks/task.c

    ./impl/app.c
)

target_include_directories(
    ${READER_APP_SRC_NAME}

    PUBLIC
        ./include
        ${READER_HAL_INTERFACE}
)

# App Executable
set(READER_APP_EXEC_NAME ${CMAKE_PROJECT_NAME}_READER_APP)

add_executable(
    ${READER_APP_EXEC_NAME}

    ./main_app_reader.c
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
