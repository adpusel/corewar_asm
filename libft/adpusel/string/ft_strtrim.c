/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:47 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
#include "string.h"
#include "../header/memory.h"

char	*ft_strtrim(char const *s)
{
	size_t	size;
	char	*s2;

	if (!s)
		return (NULL);
	while (check_char_into_str(*s, " \n\t") && *s)
		s++;
	if (!*s)
		return (ft_memory(1));
	s2 = (char*)s + (ft_strlen(s) - 1);
	size = ft_strlen(s);
	while (check_char_into_str(*s2, " \n\t"))
	{
		s2--;
		size--;
	}
	return (ft_strndup(s, size));
}
