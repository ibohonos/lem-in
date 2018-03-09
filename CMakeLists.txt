cmake_minimum_required(VERSION 3.9)
project(lem-in)

set(FLAGS "-Wall -Wextra -Werror")
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS )

include_directories(${CMAKE_SOURCE_DIR}/includes)
include_directories(${CMAKE_SOURCE_DIR}/libft/includes)

add_executable(lem-in
        srcs/ft_errors.c
        srcs/ft_init_in.c
        srcs/ft_init_rooms.c
        srcs/ft_parse_end_room.c
        srcs/ft_parse_links.c
        srcs/ft_parse_noa.c
        srcs/ft_parse_rooms.c
        srcs/ft_parse_start.c
        srcs/lem_in.c
        srcs/main.c srcs/ft_parse_start_room.c)

add_library(libft STATIC IMPORTED) # Создание статической библиотеки с именем libft
set_property(TARGET libft PROPERTY
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(lem-in libft)  # Линковка программы с библиотекой
