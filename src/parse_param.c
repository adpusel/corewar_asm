/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:24:55 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/06 17:14:45 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
static void	handle_before_param(t_asm *env, char **line, int i)
{
	if (check_char_into_str(SPACES_TABS, **line))
		asm_skip_spaces(line, SPACES_TABS);
	else if (i == 0 && **line != DIRECT_CHAR)
		handle_error(env, ERROR_PARAM);
}

static void	handle_after_param(t_asm *env, char **line, int i, int nb_param)
{
	asm_skip_spaces(line, SPACES_TABS);
	//printf("after_separator=%c\n", **line);
	if ((i < nb_param && **line != SEPARATOR_CHAR) || (i == nb_param && **line))
		handle_error(env, ERROR_PARAM);
	else if (**line)
		(*line)++;
}

static void	check_param(t_asm *env, char **line, t_instr *op, int i_param)
{
	char	c;
	int		param_check;

	c = **line;
	param_check = op->op_tab.param[i_param];
	if (c == REG_CHAR && (param_check & T_REG))
		fill_param(env, line, &(op->param[i_param]), T_REG);
	else if (c == DIRECT_CHAR && (param_check & T_DIR))
		fill_param(env, line, &(op->param[i_param]), T_DIR);
	else if (c != REG_CHAR && c != DIRECT_CHAR && (param_check & T_IND))
		fill_param(env, line, &(op->param[i_param]), T_IND);
	else
		handle_error(env, ERROR_REG);
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
		handle_before_param(env, line, i);
		check_param(env, line, current_op, i);
		i++;
		if (**line)
			handle_after_param(env, line, i, nb_param);
	}
	if (i != nb_param)
		handle_error(env, ERROR_PARAM);
}
