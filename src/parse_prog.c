/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 19:25:00 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/02 19:28:24 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


void		parse_prog(t_asm *env)
{
	char		*line;

	line = env->parser.line;
	parse_label(env, &line);
	//printf("label=%s\n", env->parser.current_label);
	ft_memdel((void**)&(env->parser.current_label));
}
