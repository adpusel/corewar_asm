/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:55:36 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/03 19:17:26 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_current_op_on_op_tab(t_asm *env, char **line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < OP_TAB_SIZE - 1)
	{
		if (ft_strnequ(
					g_op_tab[i].name
					, *line
					, (len = ft_strlen(g_op_tab[i].name))))
		{
			env->parser.current_op.op_tab = g_op_tab[i];
			*line += len;
			return ;
		}
		++i;
	}
	handle_error(env, ERROR_OP_NAME);
}

void		parse_op(t_asm *env, char **line)
{
	//t_op	*op_tab;
	//t_instr	*current_op;

	get_current_op_on_op_tab(env, line);
	printf("name=%s\n", env->parser.current_op.op_tab.name);
	//current_op = env->parser.current_op;
	//current_op->address = 
	
}
