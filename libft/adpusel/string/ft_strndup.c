/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:13 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
#include "../header/memory.h"
#include "string.h"

char	*ft_strndup(char const *s, size_t len)
{
	char *str;

	if (!s)
		return (NULL);
	str = ft_memory(len + 1);
	ft_strncpy(str, s, len);
	str[len] = 0;
	return (str);
}
