/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:11 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
#include "string.h"
#include "../header/memory.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	size_t	i;

	if (!f)
		return (NULL);
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (!(out = ft_memory(i)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = 0;
	return (out);
}
