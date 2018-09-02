project(lib_commun)

set(SOURCE_FILES
        src/ft_memcpy.c
        src/ft_memdel.c
        src/ft_memset.c
        src/ft_skip_spaces.c
        src/ft_strchr.c
        src/ft_strclen.c
        src/ft_strcmp.c
        src/ft_strdup.c
        src/ft_strjoin.c
        src/ft_strlen.c
        src/ft_strnequ.c
        src/ft_strnew.c
        src/ft_strsub.c
        src/get_next_line.c
        src/print_memory.c
        src/ft_putendl_fd.c
        )

add_library(lib_commun STATIC
        ${SOURCE_FILES}
        )

target_include_directories(lib_commun PUBLIC includes)

target_link_libraries(lib_commun libft)