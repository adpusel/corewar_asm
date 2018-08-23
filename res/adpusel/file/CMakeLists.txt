project(Corwar_lib)

set(GLOB HEADER_FILES
        includes/asm.h
        includes/ft_asm_header.h
        includes/function.h
        includes/op.h
        includes/struct.h
        )

set(SOURCE_FILES
        src/get_opcode.c
        src/op.c
        )


set(TEST_FILES
        test/all_test.c
        test/all_test.h
        test/test_label.c
        )


add_library(Corwar_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(Corwar_lib libft)