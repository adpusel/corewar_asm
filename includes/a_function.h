//
// Created by Adrien PUSEL on 8/23/18.
//

#ifndef CORWAR_GROUPE_A_FUNCTION_H
#define CORWAR_GROUPE_A_FUNCTION_H

/*
**	INIT
*/

void	init_asm(t_asm *env);

/*
**	Check_file
*/

void	check_file(t_asm *env);

/*
**	PARSER
*/

void			parse_file(t_asm *env);
/*
**    label
*/
char *start_by_label(char **string);

/*
**    error
*/

void		handle_error(t_asm *env, int err_code);

/*
**    free
*/

void		free_asm(t_asm *env);
/*
**    test
*/
int all_test();

#endif //CORWAR_GROUPE_A_FUNCTION_H
