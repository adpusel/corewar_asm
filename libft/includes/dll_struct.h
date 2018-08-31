/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sll_construct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:43:59 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLL_STRUCT_H
# define DLL_STRUCT_H

# include <stdio.h>

typedef struct			s_dll_l
{
	void				*content;
	size_t				content_size;
	struct s_dll_l		*next;
	struct s_dll_l		*prev;
}						t_dll_l;

typedef struct			s_dll
{
	size_t				length;
	int					is_ptr;
	t_dll_l				*top;
	t_dll_l				*where;
	t_dll_l				*end;
}						t_dll;

#endif
