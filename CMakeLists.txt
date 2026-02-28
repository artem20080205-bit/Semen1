cmake_minimum_required(VERSION 3.10)
project(TaskManagerProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Пути к заголовочным файлам
include_directories(include)

# Исходные файлы
set(SOURCES
    src/Task.cpp
    src/TaskManager.cpp
    src/main.cpp
)

# Создание исполняемого файла
add_executable(task_manager ${SOURCES})

# Включить отладочную информацию
set(CMAKE_BUILD_TYPE Debug)