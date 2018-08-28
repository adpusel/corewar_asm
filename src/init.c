/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:19:55 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/28 14:25:41 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		init_file(t_file *file)
{
	file->fd = 0;
	file->name = NULL;
}

static void		init_parser(t_parser *parser)
{
	parser->line = NULL;
	parser->step = 0;
	parser->i_line = 0;
	parser->i_char = 0;
//	parser->label_list = NULL;
//	parser->add_list = NULL;
}

static int		init_treat(t_treat *treat)
{
	treat->champ = (char*)malloc(sizeof(char) * (CHAMP_MAX_SIZE));
	if (!(treat->champ))
		return (ERROR_MALLOC);
	return (SUCCESS);
}

void			init_asm(t_asm *env)
{
	int	ret;

	init_file(&(env->file));
	init_parser(&(env->parser));
	ret = init_treat(&(env->treat));
	if (ret <= ERROR)
		handle_error(env, ret);
}
