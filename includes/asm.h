/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:09:37 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/06 14:13:11 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft.h"
# include "ft_library_headerd.h"
#include "struct.h"

extern t_op g_op_tab[17];

/*
**    DEFINE ========================================================
*/
# define ARG -2
# define SUCCESS 0
# define OP_TAB_SIZE 17
# define SKIP_ASM_CHAR " \t\n"
# define SPACES_TABS " \t"
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
# define ERROR_OP_NAME		-10
# define ERROR_PARAM		-11
# define ERROR_REG			-12

# include "a_function.h"

#endif
