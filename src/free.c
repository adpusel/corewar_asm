/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:30:13 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/07 11:37:04 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_gnl(t_asm *env)
{
	ft_memdel((void**)&(env->parser.line));
	if (env->file.ret > 0)
	{
		while ((env->file.ret = get_next_line(env->file.fd, &(env->parser.line))) > 0)
			ft_memdel((void**)&(env->parser.line));
		if (env->file.ret < 0)
			handle_error(env, ERROR_FD);
	}
}

void	free_asm(t_asm *env)
{
	free_gnl(env);
	ft_memdel((void**)&(env->treat.champ));
	ft_memdel((void**)&(env->parser.current_label));
}
