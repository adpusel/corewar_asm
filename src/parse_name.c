/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:22:35 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/02 19:20:06 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
 **	1 - Checker a la premiere ligne si prefixe ".name" est present
 **		et qu'il n'y a que des espaces et des tabs autour de lui
 **	2 - Lorsque le premier '"' est trouve, ecrire tous les char parcourus
 **		dans le champion
 **	3 - Repeter le processus a chaque ligne (il peut y avoir des '\n' dans
 **		le nom du champion) jusqu'au prochain char '"'
 **	4 - Verifier qu'il n y a rien derriere ce '"' a part des esp et de tabs
 **	
 **	5 - Faire passer le step a 1 pour lancer le travail sur le commentaire
 **
 */

static int		check_first_line(t_asm *env)
{
	int	i;

	i = ft_skip_spaces(env->parser.line);
	if (ft_strnequ(env->parser.line + i
		, PROG_NAME_STRING
		, PROG_NAME_STRLEN))
	{
		i += PROG_NAME_STRLEN;
		i += ft_skip_spaces(env->parser.line + i);
		if (env->parser.line[i++] != QUOTE_CHAR)
			handle_error(env, ERROR_QUOTE);
	}
	else
		handle_error(env, ERROR_HEADER);
	return (i);
}

static void		check_last_line(t_asm *env, int i)
{
	i += ft_skip_spaces(env->parser.line + i);
	if (env->parser.line[i] == '\0')
	   	env->parser.step = 1;
	else
		handle_error(env, ERROR_HEADER);
}

void			parse_name(t_asm *env)
{
	static int	first = 0;
	int			i;
	char		cur;
	t_header	*header;

	i = 0;
	if (first == 0)
	{
		i = check_first_line(env);
		first = 1;
	}
	header = &(env->parser.header);
	while ((cur = env->parser.line[i++])
		&& cur != QUOTE_CHAR
		&& header->i_name <= PROG_NAME_LENGTH)
		header->prog_name[header->i_name++] = cur;
	if (header->i_name > PROG_NAME_LENGTH)
		handle_error(env, ERROR_HEADER);
	(cur == '"') ? check_last_line(env, i++)
			: (header->prog_name[header->i_name++] = '\n');
}
