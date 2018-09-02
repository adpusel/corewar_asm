project(Corwar_lib)

file(GLOB OBJ_FILE "src/objet/*.c")
file(GLOB TEST "test/*.c")
file(GLOB DEBUG "debug/*.c")

file(GLOB SOURCES_FILES "src/*.c")

add_library(Corwar_lib STATIC
        ${OBJ_FILE}
        ${SOURCES_FILES}
        ${TEST}
        ${DEBUG}
        src/depreciate.c src/get_op.c)

target_link_libraries(Corwar_lib libft)
target_link_libraries(Corwar_lib lib_commun)
target_include_directories(Corwar_lib PUBLIC includes)
