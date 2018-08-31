project(Corwar_lib)

file(GLOB OBJ_FILE "src/objet/*.c")
file(GLOB HEADERS "includes/*.c")
file(GLOB TEST "test/*.c")
file(GLOB DEBUG "debug/*.c")



set(SOURCE_FILES
        src/get_opcode.c
        src/op.c
        src/objet/parser.c
        src/manage_dll_label.c src/codage_octet.c src/objet/address_link.c test/test_address.c includes/vendor.h)

add_library(Corwar_lib STATIC
        ${OBJ_FILE}
        ${SOURCE_FILES}
        ${TEST}
        ${DEBUG}
        )

target_link_libraries(Corwar_lib libft)