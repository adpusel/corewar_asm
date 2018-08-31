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

#ifndef LIBFT_STR_FUNCTION_H
# define LIBFT_STR_FUNCTION_H

# include <unistd.h>

/*
**  char function
*/
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isalnum(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_is_not_digit(int c);

/*
**  str function
*/
size_t	ft_how_many_char(char c, char const *str);
void	ft_putstr_fd(char const *s, int fd);
int		ft_str_eq(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
int		ft_str_join(char **dest, char const *s2, char const *s1);
size_t	ft_strlen(const char *s);
int		str_by_func(char *s, int (*f)(int));
int		check_char_into_str(char *str, char c);
ssize_t	ft_strclen(char *s, char c);
int		ft_str_dup(char **dest, const char *src);
int		ft_str_n_dup(char **dest, char const *src, size_t size);




/*
**    check str
*/
int		str_is_int(char *str, int *out);
int		is_all_number(char *s);

#endif
