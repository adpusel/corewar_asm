/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_construct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:29:11 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./dll_deep_header.h"
#include "../header/memory.h"
#include "../header/struct/dll_struct.h"
#include "../header/dll.h"
#include "../header/define.h"

t_dll_l new_dll_l(
	void *content,
	ssize_t size
)
{
	t_dll_l link;

	link = (t_dll_l) ft_memory(sizeof(t_dll_l_struc));
	if (link == NULL)
		return (NULL);
	if (size != IS_LINK)
	{
		link->content = ft_memory(size);
		if (content == NULL)
			return (NULL);
		ft_memcpy(link->content, content, size);
	}
	link->content_size = size;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

void destroy_dll_l(t_dll_l *l, void (*func)(void *))
{
	t_dll_l link;

	if (l == NULL)
		return;
	link = *l;
	if (link == NULL)
		return;
	if (link->content)
	{
		func == NULL ?
		free(link->content) :
		func(link->content);
		link->content = NULL;
	}
	link->prev = NULL;
	link->next = NULL;
	free(link);
	*l = NULL;
}

t_dll new_dll(int is_ptr)
{
	t_dll list;

	list = ft_memory(sizeof(t_dll_ptr));
	if (list)
		list->is_ptr = is_ptr;
	return (list);
}

void destroy_dll(
	t_dll *l,
	void (*func)(void *)
)
{
	t_dll list;
	t_dll_l current_link;
	t_dll_l next_link;

	if (l == NULL || *l == NULL)
		return;
	list = *l;
	current_link = list->top;
	while (current_link)
	{
		next_link = current_link->next;
		if (list->is_ptr == TRUE)
			destroy_dll_l(&current_link, no_free_content);
		else
			func == NULL ?
			destroy_dll_l(&current_link, NULL) :
			destroy_dll_l(&current_link, func);
		current_link = next_link;
	}
	list->length = 0;
	list->top = NULL;
	list->end = NULL;
	free(list);
}
