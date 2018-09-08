/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:49:15 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/08 13:17:35 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// TODO : ne pas oublier que le file doit finir par une new line

int		main(int argc, char *argv[])
{
	t_asm	*env;
	t_asm	tmp;

	env = &tmp;
	init_asm(env);
	if (argc != 2 || !(env->file.src_name = *(++argv)))
		handle_error(env, ERROR_USAGE);
	check_file(env);
	parse_file(env);
	treat_file(env);
	printf("Writing output program to %s\n", env->file.dst_name); // ft_printf
	free_asm(env);
	return (0);
}
