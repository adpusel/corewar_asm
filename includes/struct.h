/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:01:22 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/04 14:13:38 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_STRUCT_H
#define COREWAR_STRUCT_H

#include <stddef.h>
#include "asm.h"

typedef struct	s_op
{
	char 	*name;
	int 	nb_param;
	int		param[3];
	int		id;
	int		cycle;
	char	*desciption;
	int		ocp;
	int		direct_size;
}				t_op;

typedef struct	s_param
{
	int32_t		address;
	int32_t		size;
	char		*label;
	int32_t		type;
}				t_param;

typedef struct	s_instr
{
	int32_t			address;
	char			*label;
	char 			ocp;
	int32_t			size;
	t_param			param[3];
	t_op			op_tab;
} 				t_instr;


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

typedef struct		s_index
{
	int			line;
	int			character;
}					t_index;

typedef struct		s_parser
{
	t_header	header;
	char		*line;
	t_index		index;
	int			step;
	char		*current_label;
	t_instr		current_op;
	t_list		*op_list;
	t_char_tab	tab;
	t_dll		*label_list;
	t_dll		*add_list;
}					t_parser;

typedef struct		s_treat
{
	char		*champ;
	int			prog_size;
}					t_treat;

typedef struct		s_asm
{
	t_file		file;
	t_parser	parser;
	t_treat		treat;
}					t_asm;

#endif
