/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:18:32 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/14 13:15:56 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		handle_error(t_asm *env, int err_code)
{
	if (err_code == ERROR_MALLOC)
		ft_putendl_fd("Memory allocation failed", 1);
	else if (err_code == ERROR_ARG)
		ft_putendl_fd("Usage: ./asm my_champ.s", 1);
	else if (err_code == ERROR_FD)
		ft_putendl_fd("Can't read source file", 1);
	else if (err_code == ERROR_FILE_NAME)
		ft_putendl_fd("Your file name is missing the [.s] extension", 1);
	else if (err_code == ERROR_HEADER)
		ft_putendl_fd("Lexical error in [header]", 1);
	else if (err_code == ERROR_NOPROG)
		ft_putendl_fd("Not enough instructions to create a warrior", 1);
	else if (err_code == ERROR_OP_NAME)
		ft_putendl_fd("Syntax error in [champion]: instruction name", 1);
	else if (err_code == ERROR_PARAM || err_code == ERROR_REG)
		ft_putendl_fd("Syntax error in [champion]: parameter", 1);
	else if (err_code == ERROR_LABEL)
		ft_putendl_fd("Syntax error in [champion]: label", 1);
	else if (err_code == ERROR_CREAT_FILE)
		ft_putendl_fd("Can't open/create file", 1);
	else
		ft_putendl_fd("Error", 1);
	(void)env;
	free_asm(env);
	exit(-1);
}
