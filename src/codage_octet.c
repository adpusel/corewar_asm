/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codage_octet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:08:50 by adpusel           #+#    #+#             */
/*   Updated: 2018/09/03 12:09:32 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ft_asm_header.h"

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
