cmake_minimum_required(VERSION 3.9.3)

project(azimut_test_task CXX)

if (UNIX)
    find_package (Threads)
endif()

set(CMAKE_CXX_STANDARD 14)

set (SOURCES
    main.cpp

    src/reader/reader.h

    src/reader/text_file_reader/text_file_reader.h
    src/reader/text_file_reader/text_file_reader.cpp

    src/writer/writer.h

    src/writer/text_file_writer/text_file_writer.h
    src/writer/text_file_writer/text_file_writer.cpp

    src/task/task.h

    src/task/checker_task/checker_task.h
    src/task/checker_task/checker_task.cpp

    src/utils/utils.h

    src/threadpool/threadpool.h
    src/threadpool/threadpool.cpp

    src/builder/builder.h
    src/builder/builder.cpp
)

add_executable(azimut_test_task ${SOURCES})

if (UNIX)
    target_link_libraries (azimut_test_task ${CMAKE_THREAD_LIBS_INIT})
endif()