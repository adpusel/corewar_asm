/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:46:41 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/02 18:48:30 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	is_good_label(char *string)
{
	if (check_char_into_str(LABEL_CHARS, *string) == TRUE)
	{
		while (check_char_into_str(LABEL_CHARS, *string) == TRUE &&
		 check_char_into_str(LABEL_CHARS, *string) == TRUE)
			++string;
		if (*string == LABEL_CHAR)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}

void		parse_label(t_asm *env, char **line)
{
	size_t	ret;
	int		err;

	asm_skip_spaces(line, SKIP_ASM_CHAR);
	if (is_good_label(*line) == TRUE)
	{
		ret = ft_strclen(*line, ':');
		//printf("line=%s\nret=%zu\n", *line, ret);
		err = ft_dup_memory((void **)&(env->parser.current_label)
				, *line
				, ret + 1);
		if (err == MEM_LACK)
			handle_error(env, ERROR_MALLOC);
		env->parser.current_label[ret] = '\0';
		//printf("label=%s\n", env->parser.current_label);
		*line += ret;
	}
}
