/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:19:55 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/03 19:16:45 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		init_header(t_header *header)
{
	int		num;

	num = COREWAR_EXEC_MAGIC;
	header->magic = ((num>>24)&0xff)
		| ((num<<8)&0xff0000)
		| ((num>>8)&0xff00)
		| ((num<<24)&0xff000000);
}

static void		init_parser(t_parser *parser)
{
	init_header(&(parser->header));
}

void			init_asm(t_asm *env)
{
	ft_memset((void*)env, 0, sizeof(t_asm));
	init_parser(&(env->parser));
}
