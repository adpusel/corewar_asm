/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:18:32 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/11 15:15:59 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		handle_error(t_asm *env, int err_code)
{
	printf("error in %s: asm: token at [l%i]\n", env->file.src_name, env->parser.index.line);
	if (err_code == ERROR_MALLOC)
		ft_putendl_fd("je t'attendais", 2);
	if (err_code == ERROR_ARG)
		ft_putendl_fd("arg", 2);
	else if (err_code == ERROR_FD)
		ft_putendl_fd("arrete de vouloir lire des dossier avec mon programme stp", 2);
	else if (err_code == ERROR_FILE_NAME)
		ft_putendl_fd("c'est quoi ce nom de fichier ?", 2);
	else if (err_code == ERROR_QUOTE)
		ft_putendl_fd("super les quotes", 2);
	else if (err_code == ERROR_HEADER)
		ft_putendl_fd("oula va falloir revoir ton header coco", 2);
	else if (err_code == ERROR_OP_NAME)
		ft_putendl_fd("Y a un pb avec le nom de l'op, non ? tu m'as soulay", 2);
	else if (err_code == ERROR_PARAM)
		ft_putendl_fd("les params c'est pas ca", 2);
	else if (err_code == ERROR_REG)
		ft_putendl_fd("pour les registres on fait comment ?", 2);
	else if (err_code == ERROR_LABEL)
		ft_putendl_fd("label", 2);
	else if (err_code == ERROR_CREAT_FILE)
		ft_putendl_fd("create file", 2);
	else if (err_code == ERROR_SIZE_CHAMP)
		ft_putendl_fd("size champ", 2);
	free_asm(env);
	exit(-1);
}
