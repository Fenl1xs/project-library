cmake_minimum_required(VERSION 3.10)
project(WareHouseSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)


add_executable(${PROJECT_NAME}
    main.cpp
    src/Product.cpp
    src/Warehouse.cpp
    include/Product.h
    include/Warehouse.h
)
