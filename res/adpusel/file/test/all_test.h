//
// Created by Adrien PUSEL on 8/23/18.
//

#ifndef CORWAR_GROUPE_TEST_H
#define CORWAR_GROUPE_TEST_H

# include "../includes/ft_asm_header.h"

#define TEST(message, test) do { \
    if (!(test)) return message; \
                                    \
} while (0)

#define mu_run_test(TEST) do { char *message = TEST(); tests_run++; \
                                if (message) return message; } while (0)

extern int tests_run;

#define STR_EQ(str_1, str_2)  !ft_strcmp(str_1, str_2)

/*
**    function
*/
char *all_label_test();

#endif //CORWAR_GROUPE_TEST_H
