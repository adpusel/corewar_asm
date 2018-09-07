/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:48:09 by plamusse          #+#    #+#             */
/*   Updated: 2018/08/15 15:29:15 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lst_push_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return (NULL);
	if (*alst == NULL)
	{
		*alst = new;
		return (new);
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}
