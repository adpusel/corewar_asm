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
