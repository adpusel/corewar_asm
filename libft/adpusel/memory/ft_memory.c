/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:49:07 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "string.h"
#include "../header/memory.h"

void	*ft_memory(size_t size)
{
	void *mem_ptr;

	mem_ptr = malloc(size);
	if (mem_ptr == NULL)
		ft_putstr_fd("exit because : lack of memory", 2);
	else
		ft_memset(mem_ptr, 0, size);
	return (mem_ptr);
}
