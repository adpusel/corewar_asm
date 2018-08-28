//
// Created by Adrien PUSEL on 8/23/18.
//

#ifndef CORWAR_GROUPE_A_FUNCTION_H
#define CORWAR_GROUPE_A_FUNCTION_H

#include "ft_asm_header.h"


/*
**    obj
*/
int new_label_link(const char *name, size_t address, t_dll_l **link_ptr);

/*
**    define
*/
# define NO_ADDRESS -1

/*
**    label
*/
int start_by_label(char **string, char **out);
int init_parseur(t_parser *parser);

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
