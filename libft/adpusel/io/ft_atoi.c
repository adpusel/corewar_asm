/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:52:40 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi_return(long nb)
{
	if (nb < INT_MIN)
		return (0);
	else if (nb > INT_MAX)
		return (0);
	else
		return (nb);
}

int	ft_atoi(const char *s)
{
	int		i;
	long	nb;
	long	neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (s[i] == '\t' || s[i] == '\v' || s[i] == '\r' || s[i] == '\n'
			|| s[i] == '\f' || s[i] == ' ')
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		i++;
		neg = -neg;
	}
	while (s[i] <= '9' && s[i] >= '0')
	{
		nb = (nb * 10) + (s[i] - '0');
		i++;
	}
	return (ft_atoi_return(nb * neg));
}
