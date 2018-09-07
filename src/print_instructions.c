/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:48:39 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/07 16:56:58 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	print_type(int type)
{
	if (type & T_REG)
		printf("type=		REGISTRE\n");
	else if (type & T_DIR)
		printf("type=		DIRECT\n");
	else if (type & T_IND)
		printf("type=		INDIRECT\n");

}
static void	print_params(t_instr *instr)
{
	int		i;
	t_param *param;

	i = 0;
	while (i < instr->op_tab.nb_param)
	{
		param = &instr->param[i];
		printf("_-----param %i-----_\n\n", i + 1);
		print_type(param->type);
		if (param->label)
			printf("label=		%s\n", param->label);
		printf("value=		%#llx\n", param->value);
		printf("size=		%i\n", param->size);
		printf("address=	%i\n", param->address);
		printf("\n");
		i++;
	}
}

void		print_instructions(t_asm *env)
{
	t_list	*op_list;
	t_instr	*instr;
	int		i;

	op_list = env->treat.op_list;
	i = 1;
	while (op_list)
	{
		instr = ((t_instr*)(op_list->content));
		printf("_______INSTRUCTION %i | %s (%i) |_______\n\n", i++, instr->op_tab.name, instr->op_tab.op_code);
		if (instr->label)
			printf("label=		%s\n", instr->label);
		if (instr->ocp)
			printf("ocp=		%#x\n", instr->ocp);
		printf("size=		%i\n", instr->size);
		printf("address=	%i\n", instr->address);
		printf("\n");
		print_params(instr);
		printf("\n");
		op_list = op_list->next;
	}
}
