/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:38:10 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/08 12:58:28 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_extension(t_asm *env, char *file_name)
{
	if (!(file_name) || ft_strcmp(file_name + ft_strlen(file_name) - 2, ".s"))
		handle_error(env, ERROR_FILE_NAME);
}

static void	get_file_descriptor(t_asm *env, char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == ERROR)
		handle_error(env, ERROR_FD);
	env->file.fd = fd;
}

void		check_file(t_asm *env)
{
	char	*file_name;

	file_name = env->file.src_name;
	check_extension(env, file_name);
	get_file_descriptor(env, file_name);
}
