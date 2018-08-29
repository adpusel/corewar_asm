/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:19:55 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/29 16:18:20 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		init_file(t_file *file)
{
	file->fd = 0;
	file->name = NULL;
}

static void		init_header(t_header *header)
{
	int		num;

	num = COREWAR_EXEC_MAGIC;
	header->magic = ((num>>24)&0xff)
		| ((num<<8)&0xff0000)
		| ((num>>8)&0xff00)
		| ((num<<24)&0xff000000);
	ft_memset((void*)header->prog_name, 0, PROG_NAME_LENGTH + 1);
	header->i_name = 0;
	header->prog_size = 0;
	ft_memset((void*)header->comment, 0, COMMENT_LENGTH + 1);
	header->i_com = 0;
}

static void		init_parser(t_parser *parser)
{
	init_header(&(parser->header));
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
	ft_memset((void*)treat->champ, 0, CHAMP_MAX_SIZE);
	treat->i = 0;
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
