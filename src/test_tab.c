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

# include "ft_asm_header.h"

// 1 je boucle sur les char
// 2 je check les param et les stock dans un tab de char
// 	3 j'itere avec des filtres binaire sur le nb de parametre et check if true
// 4 en fonction de l'octet de codage je check la size de mon truc
//
//
// quelle peuvent etre les differentes string dans les arguments ?
// la positions des label :
// les ordre sont toujour de la form  : [label] ordre p1,p2,p3 && sur une line
// jamais d'espace entre les separateurs r et % || %:  // %r1 -> not work
// 	f
// 1 ==> on dit que le label est check // il ne faut une struc pour
// valider les info

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


// les seul separateur valable apres instructions sont :
// espaces , % // tout le reste est une err
// le separateur d'instruction est \n
// je dois ignorer tout ce qui n'est pas dans les str rechercher
//	la vm de zaz se stop quand il y a une , elle detect les %  beug avec ces truc
// j'iniore tout ce qu'il y a derrire un commentaire d'ou le concepte de ligne
// ma fonction pour les ordre et l'architecture du programme
int     test_parseur()
{
	// extraire l'ordre --> je le copy dans le cache,
		// je dois pouvoir fair la difference entre les ptr des deux chaines
		// echap les param, j'extrait avec comme separateur _ % //
	//
	// s'il existe le copier dans optab ? dans op_tab


	// split white space sur le reste de la line avec, et space
	// des que # --> stop dans chaque fonction
	return (TRUE);
}