/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:18:32 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/28 12:48:45 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		handle_error(t_asm *env, int err_code)
{
	(void)env;
	//free_env(env);
	if (err_code == ERROR_MALLOC)
		ft_putendl_fd("malloc", 2);
	else if (err_code == ERROR_FD)
		ft_putendl_fd("fd", 2);
	else if (err_code == ERROR_FILE_NAME)
		ft_putendl_fd("file name", 2);
	exit(-1);
}
