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

#include "../../includes/ft_asm_header.h"

int new_label_link(const char *name, size_t address, t_dll_l **link_ptr)
{
	int ret;
	char *cpy_label;
	t_dll_l *link;
	t_label *label_ptr;

	ret = 1
		  && new_dll_l(&label_ptr, sizeof(t_label), &link)
		  && ft_str_dup(&cpy_label, name);
	if (ret == OK)
	{
		label_ptr = link->content;
		label_ptr->name = cpy_label;
		label_ptr->address = address;
		*link_ptr = link;
	}
//	printf("%s \n", label_ptr->name);
//	printf("%lu \n", label_ptr->address);

	return (ret);
//return (555);
}
