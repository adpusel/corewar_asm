/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:24:55 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/04 18:33:55 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	parse_register(t_asm *env, char **line, t_param *param)
{
	int	nreg;

	nreg = atoi(*line);
	if (nreg > 0 && nreg <= REG_NUMBER)
	{
		param->value = nreg;
		param->type = T_REG;
		param->address = env->treat.prog_size + env->parser.current_op.size;
		param->size = 1;
		printf("%i\n", param->value);
	}
	else
		handle_error(env, ERROR_REG);
	while (nreg)
	{
		nreg = nreg / 10;
		(*line)++;
	}
	//printf("after_reg=%c\n", **line);
}

static void	check_param(t_asm *env, char **line, t_param *param)
{
	char	c;

	c = **line;
	++(*line);
	if (c == REG_CHAR)
		parse_register(env, line, param);
	//else if (c == DIRECT_CHAR)
	//	parse_direct(env, line, param);

}

void		parse_param(t_asm *env, char **line)
{
	int		i;
	int		nb_param;
	t_instr	*current_op;

	i = 0;
	current_op = &env->parser.current_op;
	nb_param = current_op->op_tab.nb_param;
	//printf("name= %s\n", current_op->op_tab.name);
	//printf("nbr_param= %d\n", current_op->op_tab.nb_param);
	while (**line && i < nb_param)
	{
		if (check_char_into_str(SKIP_SPACES_TABS, **line))
			asm_skip_spaces(line, SKIP_SPACES_TABS);
		else if (i == 0 && **line != DIRECT_CHAR)
			handle_error(env, ERROR_PARAM);
		check_param(env, line, &current_op->param[i]);
		i++;
		if (**line)
		{
			asm_skip_spaces(line, SKIP_SPACES_TABS);
//			printf("after_separator=%c\n", **line);
			if ((i < nb_param && **line != SEPARATOR_CHAR) || (i == nb_param && **line))
				handle_error(env, ERROR_PARAM);
			else if (**line)
				(*line)++;
		}
	}
}
