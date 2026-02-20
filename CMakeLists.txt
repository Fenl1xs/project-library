cmake_minimum_required(VERSION 3.10)
project(ProjectName)  # Название проекта

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

#Добавьте сюда реальные файлы
add_executable(${PROJECT_NAME}
    main.cpp
    src/Book.cpp          # Пример
    src/Library.cpp       # Пример
    include/Book.h        # Пример
    include/Library.h     # Пример
)