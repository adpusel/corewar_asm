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


//// cherche dans la liste si label existe
//int is_label_in_list(t_dll_l link, void *name)
//{
//	t_label label;
//
//	label = link->content;
//	if (ft_strcmp(label->name, name) == FALSE)
//		return (TRUE);
//	return (FALSE);
//}

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
