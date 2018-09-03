/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/08/31 12:45:52 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

void asm_clean(char **string_ptr)
{

	while (check_char_into_str(SKIP_ASM_CHAR, **string_ptr ) == TRUE)
	{
		++(*string_ptr);
	}
}

int is_good_label(char *string)
{
	if (check_char_into_str(LABEL_CHARS, *string) == TRUE)
	{
		while (check_char_into_str(LABEL_CHARS, *string) == TRUE)
			++string;
		if (*string == LABEL_CHAR)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}


int start_by_label(char **string, char **out)
{
	size_t ret;

	asm_clean(string);
	if (is_good_label(*string) == TRUE)
	{
		ret = ft_strclen(*string, ':');
		ft_dup_memory((void **)&out, *string, ret);
		*string += ret;
		return (TRUE);
	}
	else
	{
		*out = NULL;
		return (FALSE);
	}
}