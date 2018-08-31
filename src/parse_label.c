/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:46:41 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/31 12:47:07 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	is_good_label(char *string)
{
	if (check_char_into_str(LABEL_CHARS, *string) == TRUE)
	{
		while (check_char_into_str(LABEL_CHARS, *string) == TRUE)
			++string;
		if (*string == LABEL_CHAR)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}

/*
 * TODO: 
 *
 * Ajouter	-current_label a la struct parser
 *			-ERROR_LABEL
 *			
 * 
 * Free le pointeur current_label dans free.c
 *
 */

static int	parse_label(t_asm *env, char **line)
{
	size_t ret;

	asm_skip_spaces(line);
	if (is_good_label(*line) == TRUE)
	{
		ret = ft_strclen(*line, ':');
		ft_dup_memory((void **)&(env->parser.current_label), *line, ret);
		*line += ret;
	}
}
