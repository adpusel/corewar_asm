/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:49:15 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/22 14:32:19 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char *argv[])
{
	t_asm	*env;
	t_asm	tmp;

	env = &tmp;
	if (argc != 2 && !(env->file->name = ++argv))
		error(-1);
	env->file_name = 
	check_file(env);
}
