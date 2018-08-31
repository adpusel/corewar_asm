/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:18:43 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/31 13:45:46 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void asm_skip_spaces(char **line)
{
	while (check_char_into_str(SKIP_ASM_CHAR, **line) == TRUE)
		++(*line);
}

void		parse_op(t_asm *env)
{
	char		*line;

	line = (char*)env->parser.line;
	parse_label(env, &line);
}
