//
// Created by Adrien PUSEL on 8/23/18.
//

#ifndef CORWAR_GROUPE_A_FUNCTION_H
#define CORWAR_GROUPE_A_FUNCTION_H

#include "ft_asm_header.h"


/*
**    obj
*/
int new_label_link(const char *name, ssize_t address, t_dll_l **link_ptr);

/*
**    define
*/
# define NO_ADDRESS -1
# define REGISTRE 1
# define DIRECT 2
# define INDIRECT 3


/*
**    octet de codage
*/
unsigned char get_op(int p1, int p2, int p3);

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
void			parse_name(t_asm *env);
void			parse_comment(t_asm *env);
void			parse_prog(t_asm *env);
void			parse_label(t_asm *env, char **line);
void asm_skip_spaces(char **line, char *escape_str);

/*
**    label
*/
int				start_by_label(char **string, char **out);
int				init_parseur(t_parser *parser);
int				search_label_in_dll(t_dll_l *link, void *label_name_ptr);
int				mode_create(char *label_name, ssize_t address, t_dll *label_list,
   				t_dll_l **link_ptr);
int				mode_find(char *label_name, t_dll *label_list, t_dll_l **link_ptr);
int				new_address_link(t_label *label, t_dll_l **link_ptr);

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

typedef struct		s_manage_00
{
	char *tab;
	char where;
	char order;
} 					t_manage_00;
typedef t_manage_00 *t_manage;


#endif //CORWAR_GROUPE_A_FUNCTION_H
