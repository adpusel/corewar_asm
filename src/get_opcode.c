/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/08/23 15:30:38 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_asm_header.h"

// check si op est dans le tab op_tab;
// comment verifier simplement avec le tab ?

// 1 --> verifier get_op et retourner position
// 2 --> compter le nombre de parametre
// 3 --> verifier les paramemter
// 4 --> stoquer la taille de return
//
// 5 --> fonctiom

// 1 --> champ max size == la taille des champ
// je dois fermer et ouvrir le fichier a chaque fois c'est chiant
// je commence a faire les arguments avec les ptr
// je dois check les info avec le tab, c'est lui qui fait tout !
// les chamion doivent bien avoir une taille max puisque c'est celle de la memoir, c'est stupide de faire autrement !
// 2 --> commecer a faire le tab.


// faire des tests pour chaque function de TEST avec les arguments --> drive TEST dev --> pour la premiere fois
// ce nombre est l'id de tout les el de verification de ma struck

// new label link
t_dll_l new_label_link(char *name, size_t address)
{
	t_dll_l link;
	static t_label_00 label;

	label.name = name;
	label.address = address;
	link = new_dll_l(&label, sizeof(t_label_00));
	return (link);
}

// cherche dans la liste si label existe
int is_label_in_list(t_dll_l link, void *name)
{
	t_label label;

	label = link->content;
	if (ft_strcmp(label->name, name) == FALSE)
		return (TRUE);
	return (FALSE);
}

int get_int_op_tab(char *op_searched)
{
	int i = 0;
	while (i < OP_TAB_SIZE)
	{
		if (ft_strcmp(g_op_tab[i].name, op_searched) == FALSE)
			return (i);
		++i;
	}
	return (-1);
}

size_t check_nb_argv(char *curr_line_arg, size_t nb_required)
{
	size_t a;

	a = ft_how_many_char(curr_line_arg, SEPARATOR_CHAR);
	return (a == nb_required ? TRUE : FAIL);
}

int name_comment(t_parser *parser)
{
	char *line;

	line = parser->line;
	// if texte dans ma line avec le :
	return (TRUE);
}

void asm_clean(char **string_ptr)
{

	while (check_char_into_str(**string_ptr, SKIP_ASM_CHAR) == TRUE)
	{
		++(*string_ptr);
	}
}

int is_good_label(char *string)
{
	if (check_char_into_str(*string, LABEL_CHARS) == TRUE)
	{
		while (check_char_into_str(*string, LABEL_CHARS) == TRUE)
		{
			++string;
		}
		if (*string == LABEL_CHAR)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}

/**
 *
 * @param string
 * @return
 */
char *start_by_label(char **string)
{
	size_t ret;
	char *out;

	asm_clean(string);
	if (is_good_label(*string) == TRUE)
	{
		ret = ft_strchr_len(*string, ':');
		out = ft_strndup(*string, ret);
		*string += ret;
		return (out);
	}
	else
		return (NULL);
}

//int     parse_label()
//{
//
//}

int parse_line(const char *line_ptr)
{
	char *line;
	char *label;

	line = (char *)line_ptr;

	label = start_by_label(&line);
	// label --> fonction pour le handle
	// fonction pour check le peter
	// function
	//fasfa;sdjf

	return (TRUE);
}

// la fonction de recherche de mon label si je le trouve :

