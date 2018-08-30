/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:09:37 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/30 15:05:42 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft.h"
//# include "../../libft/header/struct/dll_struct.h"
//# include "struct.h"
//# include "string.h"
//# include "ft_library_headerd.h"

extern t_op g_op_tab[17];

/*
**    DEFINE ========================================================
*/
# define ARG -2
# define SUCCESS 0
# define OP_TAB_SIZE 17
# define SKIP_ASM_CHAR " \t\n"
# define PROG_NAME_STRING ".name"
# define PROG_NAME_STRLEN 5
# define COMMENT_STRING ".comment"
# define COMMENT_STRLEN 8

/*
**    ERROR ========================================================
*/

# define ERROR				-1
# define ERROR_MALLOC		-2
# define ERROR_ARG			-3
# define ERROR_FD			-4
# define ERROR_FILE_NAME	-5
# define ERROR_USAGE		-6
# define ERROR_TEST			-7
# define ERROR_QUOTE		-8
# define ERROR_HEADER		-9

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
	int			step;
	int			i_line;
	int			i_char;
//	t_dll		label_list;
//	t_dll		add_list;
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

# include "a_function.h"

#endif
