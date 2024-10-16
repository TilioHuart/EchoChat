add_executable(EchoChat
    main.cpp
    app/app.cpp
    app/user.cpp
)

set_target_properties(EchoChat PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_include_directories(EchoChat PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
