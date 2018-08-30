/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sll_construct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:43:59 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLL_DEEP_HEADER
# define DLL_DEEP_HEADER

/*
**    header vendor
*/
# include <stdio.h>


/*
**    my header
*/
# include <struct/dll_struct.h>

/*
**    function
*/
t_dll_l dll_drop_end(t_dll list);
t_dll_l dll_drop_top(t_dll list);
t_dll_l dll_drop_list_one(t_dll list);

t_dll_l dll_drop_list_one(t_dll list);
t_dll_l get_good_link(size_t index, t_dll list);
void reset_ptr_dll_l(t_dll_l link);
void no_free_content(void *link);

#endif
