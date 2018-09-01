/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:56:20 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/31 16:30:45 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void asm_skip_spaces(char **line, char *escape_str)
{
	while (check_char_into_str(escape_str, **line) == TRUE)
		++(*line);
}

void			parse_file(t_asm *env)
{
	char	*tmp;

	while ((env->file.ret = get_next_line(env->file.fd, &(env->parser.line))) > 0)
	{
		env->parser.i_line++;
		tmp = env->parser.line;
		asm_skip_spaces(&(env->parser.line), SKIP_ASM_CHAR);
		if (env->parser.line && !*(env->parser.line))
			;
		else if (env->parser.step == 0)
			parse_name(env);
		else if (env->parser.step == 1)
			parse_comment(env);
		else if (env->parser.step == 2)
			parse_op(env);
		ft_memdel((void**)&tmp);
	}
	if (env->file.ret < 0)
		handle_error(env, ERROR_FD);
	else if (env->parser.step <= ERROR)
		handle_error(env, env->parser.step);
	//printf("name=%s\n", env->parser.header.prog_name);
	//printf("comment=%s\n", env->parser.header.comment);
}
