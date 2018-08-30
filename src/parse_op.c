/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:18:43 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/30 15:05:14 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		parse_op(t_asm *env)
{

	op = ft_strsplit(env->parser.line);
	if (!op)
		handle_error(env, ERROR_MALLOC);
	i = 0;
	if (is_label(op[i]))
		handle_label(env, op[i++]);

	
}
