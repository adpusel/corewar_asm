/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 19:25:00 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/10 17:47:19 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		parse_prog(t_asm *env)
{
	char		*line;
	t_list		*new;

	line = env->parser.line;
	parse_label(env, &line);
	//printf("label=%s\n", env->parser.current_label);
	if (*line && *line != COMMENT_CHAR)
	{
		ft_memset((void*)&(env->parser.current_op), 0, sizeof(t_instr));
		parse_op(env, &line);
		parse_param(env, &line);
		//print_instruction(&env->parser.current_op, 0);
		new = ft_lstnew((void*)&env->parser.current_op, sizeof(t_instr));
		ft_lst_push_back(&env->treat.op_list, new);
		env->treat.prog_size += env->parser.current_op.size;
		//	printf("%c\n", *line);
	}
}
