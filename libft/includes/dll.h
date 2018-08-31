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

#ifndef DLL_HEADER_H
# define DLL_HEADER_H

# include <stdlib.h>
# include "align.h"

/*
**    define
*/
# define IS_PTR_LINK -1

/*
**    structure
*/
# include "dll_struct.h"

/*
**    construct ================================================================
*/
int		new_dll(int is_ptr, t_dll **dll_ptr);
void	destroy_dll(t_dll **ptr_list, void (*func)(void *));

void destroy_dll_l(t_dll_l **l, void (*func)(void *));
/**
 *
 * @param  size === IS_PTR_LINK == no copy the content
 * @return
 */
int new_dll_l(void *content, ssize_t size, t_dll_l **link_ptr);
/*
**    add ======================================================================
*/

/**
 * add in dll new_link
 * @param index == 0 			>> add start ddl
 * @param index == list.length 	>> add end dll
 * @return link add
 */

t_dll_l *dll_add_at_index(
	t_dll_l *link,
	t_dll *list,
	size_t index);

/*
**    add and create
*/
t_dll_l dll_ptr_add_create(void *link, t_dll list);

/*
**    drop =====================================================================
*/

/**
 * drop in dll new_link
 * @param index == 0 			>> drop start ddl
 * @param index == list.length 	>> drop end dll
 * @return list.lenght > 0 ? link dropped : NULL
 */
t_dll_l *dll_drop_link(t_dll *list, t_dll_l *link);

t_dll_l *dll_drop_index(t_dll *list, size_t index);

/*
**     with t_dll_ptr func ===========================================================
*/

/**
 * @param lim == ALL_LIST > search in all list
 *
 * @return func match between data and cur_link ? cur_link : NULL
 */
t_dll_l *dll_func_lim(
	t_dll *lst,
	int (*func)(t_dll_l *, void *pVoid),
	void *data_ptr,
	ssize_t lim);

#endif
