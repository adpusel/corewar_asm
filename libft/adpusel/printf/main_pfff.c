/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pfff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 17:00:07 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_library_headerd.h"

static void			fucking_norme(t_pf *pf)
{
	if (check_char_into_str(pf->specifier, "Ddi"))
		manage_decimal(pf);
	else if (check_char_into_str(pf->specifier, "Uu"))
		manage_unsigned(pf);
	else if (check_char_into_str(pf->specifier, "Oo"))
		manage_octal(pf);
	else if (check_char_into_str(pf->specifier, "Xx"))
		manage_hexa(pf);
	else if (check_char_into_str(pf->specifier, "Bb"))
		manage_binaire(pf);
}

void				send_to_good_manager(t_pf *pf)
{
	if (check_char_into_str(pf->specifier, "DdiUuOXxoBb"))
		return (fucking_norme(pf));
	if (check_char_into_str(pf->specifier, "c"))
		return (manage_char(pf));
	else if (check_char_into_str(pf->specifier, "C"))
		return (manage_char2(pf));
	else if (check_char_into_str(pf->specifier, "s"))
		return (manage_str(pf));
	else if (check_char_into_str(pf->specifier, "S"))
		return (manage_str_big(pf));
	else if (check_char_into_str(pf->specifier, "Pp"))
		return (manage_ptr(pf));
	else if (check_char_into_str(pf->specifier, "%"))
		return (manage_percent(pf));
	else if (check_char_into_str(pf->specifier, "n"))
		return (manage_n(pf));
	else if (check_char_into_str(pf->specifier, "f"))
		return (manage_float(pf));
	else
		return (manage_fuck(pf));
}

long				ft_printf(char *str, ...)
{
	va_list	ap;
	t_pf	pf;

	set_null_pf(&pf);
	va_start(ap, str);
	pf.ap = &ap;
	pf.s = &str;
	ft_set_buff(&pf.buff);
	while (ft_printf_parseur(&pf))
	{
		pf.data = 0;
		if (pf.specifier == 'f')
			pf.data = va_arg(ap, double);
		else if (check_char_into_str(pf.specifier, "DdiOoUuxXcCsSpPBbnNf"))
			pf.data = va_arg(ap, long);
		send_to_good_manager(&pf);
	}
	va_end(ap);
	ft_print_buff(&pf.buff);
	return (pf.retour);
}
