/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:18:32 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/29 17:23:33 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		handle_error(t_asm *env, int err_code)
{
	free_asm(env);
	if (err_code == ERROR_MALLOC)
		ft_putendl_fd("je t'attendais", 2);
	else if (err_code == ERROR_FD)
		ft_putendl_fd("arrete de vouloir lire des dossier avec mon programme stp", 2);
	else if (err_code == ERROR_FILE_NAME)
		ft_putendl_fd("c'est quoi ce nom de fichier ?", 2);
	else if (err_code == ERROR_HEADER)
		ft_putendl_fd("oula va falloir revoir ton header coco", 2);
	exit(-1);
}
