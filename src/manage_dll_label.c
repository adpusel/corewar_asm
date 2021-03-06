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

#include "../includes/ft_asm_header.h"

/**
 * @return == True > label == is in dll
 */
int search_label_in_dll(t_dll_l *link, void *label_name_ptr)
{
	char *label_name;
	t_label *label;

	label_name = label_name_ptr;
	label = link->content;
	if (ft_str_eq(label->name, label_name) == TRUE)
		return (TRUE);
	return (FALSE);
}

int static is_link(ssize_t address, t_label *label)
{
	int ret;

	if (label->address == NO_ADDRESS)
	{
		label->address = address;
		ret = OK;
	}
	else
		ret = FAIL;
	return (ret);
}

/**
 * @brief 	cherche le label dans la label_name, s'il existe et a une address
 * 			return une err. Sinon l'update ou le creer. Le link est placer dans
 * 			ptr_link
 * 			
 * @param label_name label rechercher
 * @param address address du label_name
 * @param label_name list de tout les label
 * @param link_ptr out pour le label trouve
 *
 * @return OK || MEM_LACK || FAIL --> si le label existe et a une address
 */
int mode_create(char *label_name,
	ssize_t address,
	t_dll *label_list,
	t_dll_l **link_ptr)
{
	t_dll_l *link;
	int ret;

	link = dll_func_lim(label_list, search_label_in_dll, label_name, ALL_LIST);
	if (link != NULL)
	{
		ret = is_link(address, link->content);
	}
	else
	{
		ret = new_label_link(label_name, address, &link);
		if (ret)
			dll_add_at_index(link, label_list, label_list->length);
	}
	*link_ptr = link;
	return (ret);
}

/**
 * \do met dans link_ptr le link contenant l'address de label_name
 *  si le link n'existe pas, il est creer
 *
 * @param label_name label rechercher
 * @param label_list list de tout les label
 * @param link_ptr link de sortie
 * @return OK || MEM_LACK
 */
int mode_find(char *label_name,
	t_dll *label_list,
	t_dll_l **link_ptr)
{
	t_dll_l *link;
	int ret;

	ret = OK;
	link = dll_func_lim(label_list, search_label_in_dll, label_name, ALL_LIST);
	if (link == NULL)
	{
		ret = new_label_link(label_name, NO_ADDRESS, &link);
		if (ret)
			dll_add_at_index(link, label_list, label_list->length);
	}
	*link_ptr = link;
	return (ret);
}