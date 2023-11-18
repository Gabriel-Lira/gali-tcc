cmake_minimum_required(VERSION 3.20)

## Sources
set(
    serial_SRCS_FILES

    ./serial/src/serial.cc
)

if(APPLE)
    # If OSX
    list(APPEND serial_SRCS_FILES ./serial/src/impl/unix.cc)
    list(APPEND serial_SRCS_FILES ./serial/src/impl/list_ports/list_ports_osx.cc)
elseif(UNIX)
    # If unix
    list(APPEND serial_SRCS_FILES ./serial/src/impl/unix.cc)
    list(APPEND serial_SRCS_FILES ./serial/src/impl/list_ports/list_ports_linux.cc)
else()
    # If windows
    list(APPEND serial_SRCS_FILES ./serial/src/impl/win.cc)
    list(APPEND serial_SRCS_FILES ./serial/src/impl/list_ports/list_ports_win.cc)
endif()

# Lib
add_library(
    serial_SRCS

    ${serial_SRCS_FILES}
)

target_include_directories(
    serial_SRCS

    PUBLIC
        ./serial/include
)

target_compile_features(
    serial_SRCS

    PUBLIC
        c_std_11
        cxx_std_17
)

if(APPLE)
    target_link_libraries(serial_SRCS ${FOUNDATION_LIBRARY} ${IOKIT_LIBRARY})
elseif(UNIX)
    target_link_libraries(serial_SRCS rt pthread)
else()
    target_link_libraries(serial_SRCS setupapi)
endif()
