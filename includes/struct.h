#ifndef COREWAR_STRUCT_H
#define COREWAR_STRUCT_H

#include <stddef.h>
#include "asm.h"

typedef struct s_op
{
	char name[6];
	int nb_par;
	int param[3];
	int id;
	int cycle;
	char desciption[100];
	int direct_size;
	int other;
} t_op;

typedef struct		s_label_00
{
	const char *name;
	ssize_t address;
}					t_label;

typedef struct		s_address
{
	size_t address;
	int size;
	t_label label_ptr;
}					t_address_00;
typedef t_address_00 *t_address;

typedef struct		s_debug
{
	int show_label;
}					t_debug;

typedef struct		s_char_tab
{
	char		*tab;
	size_t		where;
}					t_char_tab;

typedef struct		s_parser
{
	const char	*line;
	int			step;
	int			i_line;
	int			i_char;
	t_char_tab	tab;
	char		*where;
	t_dll		*label_list;
	t_dll		*address;
}					t_parser;

#endif