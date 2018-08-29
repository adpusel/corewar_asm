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
