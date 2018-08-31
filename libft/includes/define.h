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

#ifndef LIBFT_DEFINE_H
# define LIBFT_DEFINE_H

/*
**    code err ret
*/
# define MEM_LACK -1
# define PTR_NULL 2

# define TRUE 1
# define OK 1
# define DONE 1
# define END 0
# define FALSE 0
# define FAIL 0
# define NO 654
# define YES 536465

# define ACTIVATE 1
# define DISABLE 0

/*
**    dll
*/
# define TOP_LIST 0
# define END_LIST 1
# define ALL_LIST -1
# define DISABLE 0


# define ALLOC_MEM(ret, function) \
			if (ret == OK)			 \
				ret = (function);
# define IF_MEM_FREE(instruct) \
			if (ret == OK) { instruct}
#endif
