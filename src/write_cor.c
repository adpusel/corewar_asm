/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 12:57:12 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/08 13:18:21 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_file_dst_name(t_asm *env)
{
	int		src_len;

	src_len = ft_strlen(env->file.src_name);
	env->file.dst_name = (char*)malloc(sizeof(char) * (src_len + 2));
	ft_memset(env->file.dst_name, 0, src_len + 2);
	ft_memcpy(env->file.dst_name, env->file.src_name, src_len - 2);
	ft_strlcat(env->file.dst_name, ".cor", src_len + 3);
}

void		write_cor(t_asm *env)
{
	int		fd;

	get_file_dst_name(env);
	fd = open(
			env->file.dst_name
			, O_WRONLY | O_CREAT | O_TRUNC
			, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		handle_error(env, ERROR_CREAT_FILE);
	write(fd, (void*)&env->parser.header, sizeof(t_header));	
	write(fd, env->treat.champ, env->treat.prog_size);
	close(fd);
}
