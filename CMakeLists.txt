cmake_minimum_required(VERSION 3.19)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c
                        ft_atoi.c utils_for_life_1.c
        utils_for_time_1.c
        main_utils_1.c
        )