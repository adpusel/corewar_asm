/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:15:50 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/07 16:56:57 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		put_params(char *champ, t_instr *instr, int *i)
{
	int		i_param;
	int		i_byte;
	char	value[4];
	t_param	*param;

	i_param = 0;
	i_byte = 3;
	while (i_param < instr->op_tab.nb_param)
	{
		param = &instr->param[i_param++];
		value[] = param->value;

// ICI
		*i = *i + param->size;
	}
}
void		translate_to_bytecode(t_asm *env)
{
	t_list	*op_list;
	t_instr	*instr;
	char	*champ;
	int		i;

	env->treat.champ = (char*)malloc(sizeof(char) * (env->treat.prog_size + 1));
	if (!env->treat.champ)
		handle_error(env, ERROR_MALLOC);
	champ = env->treat.champ;
	op_list = env->treat.op_list;
	i = 0;
	while (op_list)
	{
		instr = ((t_instr*)(op_list->content));
		champ[i++] = instr->op_tab.op_code;
		if (instr->ocp)
			champ[i++] = instr->ocp;
		put_params(champ, instr, &i);
		op_list = op_list->next;
	}
}

static void	write_cor(t_asm *env)
{
	int		fd;

	fd = open(
			"my_champ.cor"
			, O_WRONLY | O_CREAT | O_TRUNC
			, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		handle_error(env, ERROR_CREAT_FILE);
	write(fd, (void*)&env->parser.header, sizeof(t_header));	
	write(fd, "my byte", 7);
}

void		treat_file(t_asm *env)
{
	translate_to_bytecode(env);
	write_cor(env);
}
