/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 19:25:00 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/06 16:40:04 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		parse_prog(t_asm *env)
{
	char		*line;

	line = env->parser.line;
	parse_label(env, &line);
	//printf("label=%s\n", env->parser.current_label);
	if (*line)
	{
		ft_memset((void*)&(env->parser.current_op), 0, sizeof(t_instr));
		parse_op(env, &line);
		parse_param(env, &line);
		env->treat.prog_size += env->parser.current_op.size;
		//	printf("%c\n", *line);
	}
}
