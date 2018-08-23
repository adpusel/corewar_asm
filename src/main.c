/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:49:15 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/23 14:38:27 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char *argv[])
{
	t_asm	*env;
	t_asm	tmp;

	env = &tmp;
	if (argc != 2 && !(env->file->name = *(++argv)))
		handle_error(env, ERROR_USAGE);
	env->file_name = *(++argv);
	check_file(env);
	parse_file(env);
}
