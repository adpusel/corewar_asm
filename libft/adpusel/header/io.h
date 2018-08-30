/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sll_construct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:43:59 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGV_H
# define ARGV_H
# include <ntsid.h>

# define GNL_BUFF 512

typedef struct		s_gnl
{
	char			*str;
	int				fd;
	int				r_stt;
	struct s_gnl	*next;
}					t_gnl;


/*
**    gnl ======================================================================
*/

/**
 *
 * @param fd			get by open file
 * @param line			out for the new line
 * @param nb_line_ptr	nb of the current line
 * @return
 * 			1 ==> while not EFO\n
 * 			0 ==> if EFO
 */
int					get_next_line(const int fd, char **line);
int					ask_gnl(int fd, char **line, size_t *nb_line_ptr);

int					ft_error(char *str);
int					open_file(char *name);
void				raise_errno(void *ptr);
int					ft_atoi(const char *s);

/*
**    error funtion
*/
int errno_exit();

#endif
