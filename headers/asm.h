/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:09:37 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/22 16:15:58 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H

/*
**    DEFINE ========================================================
*/

#include <libft/include/struct/dll_struct.h>

#define ARG -2
#define SUCCESS 0
#define OP_TAB_SIZE 17
#define SKIP_ASM_CHAR " \t"

typedef struct		s_file
{
	int			fd;
	char		*name;
}					t_file;

typedef struct		s_parser
{
	char		*line;
	int			step;
	int			i_line;
	int			i_char;
	t_dll		label_list;
	t_dll		add_list;
}					t_parser;

typedef struct		s_treat
{
	char		*champ;
}					t_treat;

typedef struct		s_asm
{
	t_file		file;
	t_parser	parser;
	t_treat		treat;
}					t_asm;

#endif