/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:24:35 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../header/struct/dll_struct.h"
#include "../../header/define.h"

typedef struct		s_label_00
{
	char *name;
	int  add;
} 					t_label_00;
typedef t_label_00 *t_label;



int test(t_dll_l link, void* name)
{
	t_label label;
	label = link->content;

	if (ft_strcmp(label->name, name))
		return (TRUE);
	return FALSE;
}


t_dll_l dll_func_lim
	(
		t_dll lst,
		int (*func)(t_dll_l *, void *),
		void *data_ptr,
		ssize_t lim
	)
{
	t_dll_l link;

	link = lst->top;
	lim = lim == -1 ? lst->length : lim;
	while (lim)
	{
		if (func(link->content, data_ptr) == TRUE)
			return (link);
		link = link->next;
		--lim;
	}
	return (NULL);
}
