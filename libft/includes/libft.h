/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 13:37:21 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/28 17:50:19 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h> 
# include <fcntl.h>

# include "print_memory.h"

/*
**		DEFINE
*/

# define GNL_BUFF_SIZE 32

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/*
**		STRING
*/

void	ft_putendl_fd(char const *s, int fd);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int			ft_skip_spaces(char *str);
int		get_next_line(int const fd, char **line);

/*
**		MEMORY
*/

void	ft_memdel(void **ap);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*print_memory(void *addr, unsigned long size);

#endif
