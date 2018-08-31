/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:18:43 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/31 16:30:51 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


void		parse_op(t_asm *env)
{
	char		*line;

	line = (char*)env->parser.line;
	parse_label(env, &line);
	printf("label=%s\n", env->parser.current_label);
	ft_memdel((void**)&(env->parser.current_label));
}
