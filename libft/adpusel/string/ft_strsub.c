/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:47 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
#include "../header/memory.h"
#include "string.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *out;

	if (!s)
		return (NULL);
	out = ft_memory(len + 1);
	ft_strncpy(out, s + start, len);
	out[len] = 0;
	return (out);
}
