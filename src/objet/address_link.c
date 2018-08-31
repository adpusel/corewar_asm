/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:38:10 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/23 14:31:27 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int new_address_link(t_label *label, t_dll_l **link_ptr)
{
	t_dll_l *link;
	t_address *address_ptr;
	int ret;

	if (label == NULL || link_ptr == NULL)
	{
		*link_ptr = NULL;
		return (PTR_NULL);
	}
	ret = new_dll_l(&address_ptr, sizeof(t_address), &link);
	if (ret == OK)
	{
		address_ptr = link->content;
		address_ptr->label_ptr = label;
		*link_ptr = link;
	}
	return (ret);
}

void set_address_link(size_t address_instruction,
	size_t address_param,
	size_t size_param, t_address *address)
{
	address->address_instruction = address_instruction;
	address->address_param = address_param;
	address->size_param = size_param;
}