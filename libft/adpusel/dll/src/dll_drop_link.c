/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:23:40 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dll_deep_header.h"
#include "../../header/struct/dll_struct.h"

t_dll_l	dll_drop_link(t_dll list, t_dll_l link)
{
	t_dll_l prev_link;
	t_dll_l next_link;

	if (link == NULL || list == NULL)
		return (NULL);
	if (list->length == 1)
		return (dll_drop_list_one(list));
	else if (link == list->top)
		return (dll_drop_top(list));
	else if (link == list->end)
		return (dll_drop_end(list));
	else
	{
		next_link = link->next;
		prev_link = link->prev;
		next_link->prev = prev_link;
		prev_link->next = next_link;
		reset_ptr_dll_l(link);
		list->length -= 1;
		return (link);
	}
}
