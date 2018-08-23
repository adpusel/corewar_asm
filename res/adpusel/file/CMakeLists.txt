project(Corwar_lib)

set(HEADER_FILES
        includes/function.h
        includes/op.h
        includes/asm.h
        includes/struct.h
        includes/ft_asm_header.h
        includes/all_test.h
        )

set(SOURCE_FILES
        src/get_opcode.c
        src/op.c
        test/all_test.c
        test/test_label.c)

add_library(Corwar_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(Corwar_lib libft)