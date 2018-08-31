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

#include "ft_library_headerd.h"

int new_dll_l(void *content, ssize_t size, t_dll_l **link_ptr)
{
	t_dll_l *link;
	void *ptr_mem_content;
	int ret;

	ret = ft_memory((void **) &link, sizeof(t_dll_l));
	if (ret && size != IS_PTR_LINK)
		ret = ft_dup_memory(&ptr_mem_content, content, size);
	if (ret == OK)
	{
		if (size != IS_PTR_LINK)
		    link->content = ptr_mem_content;
		else
			link->content = content;
		link->content_size = size;
		link->next = NULL;
		link->prev = NULL;
		*link_ptr = link;
	}
	else
		*link_ptr = NULL;
	return (ret);
}

void destroy_dll_l(t_dll_l **l, void (*func)(void *))
{
	t_dll_l *link;

	if (l == NULL || *l == NULL)
		return;
	link = *l;
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

int new_dll(int is_ptr, t_dll **dll_ptr)
{
	static int ret;

	ret = ft_memory((void **) dll_ptr, sizeof(t_dll));
	if (ret == OK && is_ptr == TRUE)
		(*dll_ptr)->is_ptr = is_ptr;
	return (ret);
}

void destroy_dll(
 t_dll **l,
 void (*func)(void *)
)
{
	t_dll *list;
	t_dll_l *current_link;
	t_dll_l *next_link;

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
