#ifndef COREWAR_STRUCT_H
#define COREWAR_STRUCT_H

#include <stddef.h>

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
	char *name;
	size_t address;
}					t_label_00;
typedef t_label_00 *t_label;

typedef struct		s_address_00
{
	size_t address;
	int size;
	t_label label_ptr;
}					t_address_00;
typedef t_address_00 *t_address;

#endif