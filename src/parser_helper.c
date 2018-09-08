/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:11:24 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/08 13:49:09 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void asm_skip_spaces(char **line, char *escape_str)
{
	while (check_char_into_str(escape_str, **line))
		++(*line);
}
