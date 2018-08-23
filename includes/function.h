#ifndef FUNCTION_H
# define FUNCTION_H

/*
**    var global ========================================================
*/
# include "op.h"
# include "struct.h"

extern t_op g_op_tab[17];

/*
**    manage_op_tab
*/
int get_int_op_tab(char *op_searched);

/*
**    manage label
*/
char *start_by_label(char **string);


/*
**    test
*/
char *all_label_test();

#endif
