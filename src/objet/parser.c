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

#include "../../includes/vendor.h"

/**
 * initialise les deux containeur de list chainees
 * @param parser
 * @return return la reponse de malloc
 */
int init_parseur(t_parser *parser)
{
	int ret;

	ret = 1
		&& new_dll(FALSE, &parser->label_list)
		&& new_dll(FALSE, &parser->address);
	return (ret);
}