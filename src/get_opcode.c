/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/08/31 12:45:52 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_asm_header.h"

int get_int_op_tab(char *op_searched)
{
	int i = 0;
	while (i < OP_TAB_SIZE)
	{
		if (ft_str_eq(g_op_tab[i].name, op_searched) == OK)
			return (i);
		++i;
	}
	return (-1);
}

size_t check_nb_argv(char *curr_line_arg, size_t nb_required)
{
	size_t a;

	a = ft_how_many_char(SEPARATOR_CHAR, curr_line_arg);
	return (a == nb_required ? TRUE : FAIL);
}

int name_comment(t_parser *parser)
{
	char *line;

	line = (char *)parser->line;
	// if texte dans ma line avec le :
	return (TRUE);
}

void asm_clean(char **string_ptr)
{

	while (check_char_into_str(SKIP_ASM_CHAR, **string_ptr ) == TRUE)
	{
		++(*string_ptr);
	}
}

int is_good_label(char *string)
{
	if (check_char_into_str(LABEL_CHARS, *string) == TRUE)
	{
		while (check_char_into_str(LABEL_CHARS, *string) == TRUE)
			++string;
		if (*string == LABEL_CHAR)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}


// TODO: fonction de debug de mon label
	// comme

/**
 *
 * @param string
 * @return
 */
int start_by_label(char **string, char **out)
{
	size_t ret;

	asm_clean(string);
	if (is_good_label(*string) == TRUE)
	{
		ret = ft_strclen(*string, ':');
		ft_dup_memory((void **)&out, *string, ret);
		*string += ret;
		return (TRUE);
	}
	else
	{
		*out = NULL;
		return (FALSE);
	}
}

// cet fonction get un label et, ret
// je cherche la
int manage_label_dll(const char *label, t_parser parser)
{
	(void)label;
	t_dll *list_label;

	list_label = parser.label_list;
	return (FALSE);
}

// TODO gere l'avancement dans les tab de char ? le penser comme un obj
// quand j'ecris dedans elle keep l'octet ou je suis,
// le dernier ordre pour cet l'address de :
// le label et des autres tu

int parse_line(const t_parser parser)
{
	char *line;
	char *label;


	line = (char *) parser.line;
	if (start_by_label(&line, &label) == TRUE)
	{

	}
	// si label ok ==> je fais :
	// fonction pour check le peter
	// function
	return (TRUE);
}

// la fonction de recherche de mon label si je le trouve :
