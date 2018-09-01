cmake_minimum_required(VERSION 3.9.4)

set(PROJECT_NAME CORWAR_GROUPE)

#*------------------------------------*\
#    --  NAME PROJET  --
#*------------------------------------*/
project(${PROJECT_NAME})

#*------------------------------------*\
#    --  COMPILATEUR OPTION  --
#*------------------------------------*/
set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

#-fsanitize=memory-fsanitize-memory-track-origins=2 -fsanitize=address


add_executable(
        Corewar_run
        main.c
)
#*------------------------------------*\
#    --  PATH  --
#*------------------------------------*/
set(REPO "file/")

#*------------------------------------*\
#    -- LIB FT FILE --
#*------------------------------------*/
#include_directories(libft)
add_subdirectory(libft)

#include_directories(proj_lib)
add_subdirectory(proj_lib)

#*------------------------------------*\
#    project file
#*------------------------------------*/
add_subdirectory(file)

#*------------------------------------*\
#    TEST
#*------------------------------------*/


#*------------------------------------*\
#    linking
#*------------------------------------*/
target_link_libraries(Corewar_run Corwar_lib )
target_link_libraries(Corewar_run libft)
target_link_libraries(Corewar_run lib_commun)