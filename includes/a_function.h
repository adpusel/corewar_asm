//
// Created by Adrien PUSEL on 8/23/18.
//

#ifndef CORWAR_GROUPE_A_FUNCTION_H
#define CORWAR_GROUPE_A_FUNCTION_H

/*
**    label
*/
char *start_by_label(char **string);

/*
**    error
*/

void		handle_error(t_asm *env, int err_code);

/*
**    test
*/
int all_test();

#endif //CORWAR_GROUPE_A_FUNCTION_H
