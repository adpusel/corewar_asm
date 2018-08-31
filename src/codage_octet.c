/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/08/23 15:30:38 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_asm_header.h"

unsigned char get_op(int p1, int p2, int p3)
{
	unsigned char oc_codage;

	oc_codage = 0;
	oc_codage += p1;
	oc_codage = oc_codage << 2;
	oc_codage += p2;
	oc_codage = oc_codage << 2;
	oc_codage += p3;
	oc_codage = oc_codage << 2;
	return (oc_codage);
}