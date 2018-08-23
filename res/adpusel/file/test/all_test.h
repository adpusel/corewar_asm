//
// Created by Adrien PUSEL on 8/23/18.
//

#ifndef CORWAR_GROUPE_TEST_H
#define CORWAR_GROUPE_TEST_H

#define TEST(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(TEST) do { char *message = TEST(); tests_run++; \
                                if (message) return message; } while (0)

extern int tests_run;

# include "../includes/ft_asm_header.h"

/*
**    function
*/
char *test_label();


#endif //CORWAR_GROUPE_TEST_H
