/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:56:20 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/28 18:18:00 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			parse_file(t_asm *env)
{
	int	ret;

	ret = 0;
	while ((ret = get_next_line(env->file.fd, &(env->parser.line))) > 0)
	{
		env->parser.i_line++;
		//printf("line=%s\n", env->parser.line);
		if (env->parser.step == 0)
			parse_name(env);
		else if (env->parser.step == 1)
			;//parse_comment(env);
		else if (env->parser.step == 2)
			;//parse_line(env);
		free(env->parser.line);
	}
	print_memory(env->treat.champ, 16);
	printf("ok\n");
	if (ret < 0)
		handle_error(env, ERROR_FD);
}
