/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:56:20 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/11 18:50:10 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		fill_header(t_asm *env)
{
	env->parser.header.prog_size = little_endian(env->treat.prog_size);
	env->parser.header.magic = little_endian(COREWAR_EXEC_MAGIC);

}
void			parse_file(t_asm *env)
{
	char	*tmp ;

	while ((env->file.ret = get_next_line(env->file.fd, &(env->parser.line))) > 0)
	{
		env->parser.index.line++;
		tmp = env->parser.line;
		asm_skip_spaces(&tmp, SKIP_ASM_CHAR);
		if (tmp && (!*tmp || *tmp == COMMENT_CHAR))
			;
		else if (env->parser.step < 2)
			parse_header(env);
		else
			parse_prog(env);
		ft_memdel((void**)&(env->parser.line));
	}
	if (env->file.ret < 0)
		handle_error(env, ERROR_FD);
	else if (env->parser.step <= ERROR)
		handle_error(env, env->parser.step);
	fill_label(env);
	fill_header(env);
	//print_instructions(env);
	//printf("prog_size=%i\n", env->treat.prog_size);
	//printf("name=%s\n", env->parser.header.prog_name);
	//printf("comment=%s\n", env->parser.header.comment);
}
