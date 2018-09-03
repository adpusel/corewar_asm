/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:56:20 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/03 19:12:19 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			parse_file(t_asm *env)
{
	char	*tmp ;

	while ((env->file.ret = get_next_line(env->file.fd, &(env->parser.line))) > 0)
	{
		env->parser.index.line++;
		tmp = env->parser.line;
		asm_skip_spaces(&tmp, SKIP_ASM_CHAR);
		if (tmp && !*tmp)
			;
		else if (env->parser.step == 0)
			parse_name(env);
		else if (env->parser.step == 1)
			parse_comment(env);
		else if (env->parser.step == 2)
			parse_prog(env);
		ft_memdel((void**)&(env->parser.line));
	}
	if (env->file.ret < 0)
		handle_error(env, ERROR_FD);
	else if (env->parser.step <= ERROR)
		handle_error(env, env->parser.step);
	//printf("name=%s\n", env->parser.header.prog_name);
	//printf("comment=%s\n", env->parser.header.comment);
}
