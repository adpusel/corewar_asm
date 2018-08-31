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
	size_t address_instruction;
	size_t address_param;
	size_t size_param;
	t_label *label_ptr;
}					t_address;

typedef struct		s_debug
{
	int show_label;
}					t_debug;

typedef struct		s_char_tab
{
	char		*tab;
	size_t		where;
}					t_char_tab;

typedef struct		s_file
{
	int			fd;
	int			ret;
	char		*name;
}					t_file;

typedef struct		s_parser
{
	t_header	header;
	char		*line;
	t_char_tab	tab;
	int			step;
	int			i_line;
	int			i_char;
	t_dll		label_list;
	t_dll		add_list;
}					t_parser;

typedef struct		s_treat
{
	char		*champ;
	int			i;
}					t_treat;

typedef struct		s_asm
{
	t_file		file;
	t_parser	parser;
	t_treat		treat;
}					t_asm;

#endif