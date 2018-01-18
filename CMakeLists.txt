cmake_minimum_required(VERSION 3.8)
project(ueb05Naji)

set(CMAKE_CXX_STANDARD 11)

include_directories("header" "src")

set(SOURCE_FILES
        header/database.h
        header/datastructure.h
        header/datetime.h
        header/menu.h
        header/sort.h
        header/teams.h
        header/tools.h
        src/database.c
        src/datetime.c
        src/little_teams.xml
        src/main.c
        src/menu.c
        src/sort.c
        src/teams.c
        src/xml/teams.xml
        src/tools.c)

add_executable(ueb05Naji ${SOURCE_FILES})
