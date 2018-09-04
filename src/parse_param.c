/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:24:55 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/04 14:19:11 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	parse_register(t_asm *env, char **line, t_instr *current_op, int i_param)
{
	int	reg;
	(void)env;
	(void)current_op;
	(void)i_param;
	reg = atoi(*line);
	printf("%i\n", reg);
	return ;
}

static void	check_param(t_asm *env, char **line, t_instr *current_op, int i_param)
{
	char	c;

	c = **line;
	++(*line);
	if (c == REG_CHAR)
		parse_register(env, line, current_op, i_param);
}

void		parse_param(t_asm *env, char **line)
{
	int		i;
	t_instr	*current_op;

	i = 0;
	current_op = &env->parser.current_op;
	//printf("name= %s\n", current_op->op_tab.name);
	//printf("nbr_param= %d\n", current_op->op_tab.nb_param);
	while (i < current_op->op_tab.nb_param)
	{
		if (check_char_into_str(SKIP_SPACES_TABS, **line))
			asm_skip_spaces(line, SKIP_SPACES_TABS);
		else if (i == 0 && **line != DIRECT_CHAR)
			handle_error(env, ERROR_PARAM);
		check_param(env, line, current_op, i);
		if (**line)
		{
			(*line)++;
			//printf("after_separator=%c\n", **line);
		}
		i++;
	}
}
