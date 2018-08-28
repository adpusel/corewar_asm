project(Corwar_lib)

set(HEADER_FILES
        includes/asm.h
        includes/ft_asm_header.h
        includes/op.h
        includes/struct.h
        includes/a_function.h)

set(SOURCE_FILES
        src/get_opcode.c
        src/op.c
        src/objet/parser.c)


set(TEST_FILES
        test/all_test.c
        test/all_test.h
        test/test_label.c
        test/test_find_label.c)

set(DEBUG_FILES
        test/all_test.c
        test/all_test.h
        test/test_label.c
        test/test_find_label.c debug/debug_main.c src/objet/label_link.c)


add_library(Corwar_lib STATIC
        ${SOURCE_FILES}
        ${HEADER_FILES}
        ${TEST_FILES}
        ${DEBUG_FILES}
        )

target_link_libraries(Corwar_lib libft)