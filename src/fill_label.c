/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13:42:48 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/07 14:45:37 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//static void	compute_label_value(int	cur_addr, int match_addr, t_param *param)
//{
//	if (cur_addr < match_addr)
//		param->value = match_addr 
//
//
//}

static void	fill_label_value(t_asm *env, t_instr *cur, t_param *param)
{
	t_list		*op_list;
	t_instr		*match;

	op_list = env->treat.op_list;
	while (op_list)
	{
		match = ((t_instr*)(op_list->content));
		if (match->label)
		{
			if (ft_strequ(param->label, match->label))
			{
				param->value = match->address - cur->address;
				return ;
			}
		}
		op_list = op_list->next;
	}
	handle_error(env, ERROR_LABEL);
}

void		fill_label(t_asm *env)
{
	t_list		*op_list;
	t_instr		*cur;
	t_param		*param;
	int			i;

	op_list = env->treat.op_list;
	while (op_list)
	{
		cur = ((t_instr*)(op_list->content));
		i = 0;
		while (i < cur->op_tab.nb_param)
		{
			param = &cur->param[i];
			if (param->label)
				fill_label_value(env, cur, param);
			i++;
		}
		op_list = op_list->next;
	}
}
