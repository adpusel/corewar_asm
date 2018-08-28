/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:56:20 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/28 12:21:15 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		init_parser(t_parser *parser)
{
	parser->line = NULL;
	step = 0;
	i_line = 0;
	i_char = 0;
	label_list = NULL;
	add_list = NULL;
}

static void		init_treat(t_treat *treat)
{
	env->treat->champ = (char*)malloc(sizeof(char) * (CHAMP_MAX_SIZE));
	if (!(env->treat->champ))
		handle_error(env, ERROR_MALLOC);
}

void			parse_file(t_asm *env)
{
	int	ret;

	init_parser(env->parser);
	init_treat(env->treat);
	ret = 0;
	while ((ret = get_next_line(env->file->fd, &(env->parser->line))) > 0)
	{
		if (env->parser->step == 0)
			parse_name(env);
		else if (env->parser->step == 1)
			parse_comment(env);
		else if (env->parser->step == 2)
			parse_line(env);
		free(line);
	}
	if (ret < 0)
		handle_error(env, ERROR_FD);
}
