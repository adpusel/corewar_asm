/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:22:35 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/28 18:18:00 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			parse_name(t_asm *env)
{
	static int	first = 0;
	int			i;
	char		cur;

	i = 0;
	if (first == 0)
	{
		i = ft_skip_spaces(env->parser.line);
		if (ft_strnequ(env->parser.line + i, ".name", 5))
		{
			i += 5;
			i += ft_skip_spaces(env->parser.line + i);
			if (env->parser.line[i] != '"')
				handle_error(env, ERROR_QUOTE);
			i++;
		}
		first = 1;
	}
	while ((cur = env->parser.line[i++]) && cur != '"')
		(env->treat.champ)[env->treat.i++] = cur;
	printf("%c\n", cur);
	if (cur == '"')
		env->parser.step = 1;
	//printf("line=%s\n", env->parser.line + i);
}
