/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:27:20 by plamusse          #+#    #+#             */
/*   Updated: 2018/09/07 16:00:44 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	cf parse_name.c pour plus d'info
*/

static int		check_first_line(t_asm *env)
{
	int	i;

	i = ft_skip_spaces(env->parser.line);
	if (ft_strnequ((env->parser.line + i)
		, COMMENT_STRING
		, COMMENT_STRLEN))
	{
		i += COMMENT_STRLEN;
		i += ft_skip_spaces(env->parser.line + i);
		if (env->parser.line[i++] != QUOTE_CHAR)
			handle_error(env, ERROR_QUOTE);
	}
	else
		handle_error(env, ERROR_HEADER);
	return (i);
}

static void		check_last_line(t_asm *env, int i)
{
	i += ft_skip_spaces(env->parser.line + i);
	if (env->parser.line[i] == '\0')
	   	env->parser.step = 2;
	else
		env->parser.step = ERROR;
}

void			parse_comment(t_asm *env)
{
	static int	first = 0;
	int			i;
	char		cur;
	t_parser	*parser;
	t_header	*header;

	i = 0;
	if (first == 0)
	{
		i = check_first_line(env);
		first = 1;
	}
	parser = &(env->parser);
	header = &(env->parser.header);
	while ((cur = parser->line[i++])
		&& cur != QUOTE_CHAR
		&& parser->i_com <= COMMENT_LENGTH)
		header->comment[parser->i_com++] = cur;
	if (parser->i_com > COMMENT_LENGTH)
		handle_error(env, ERROR_HEADER);
	(cur == QUOTE_CHAR) ? check_last_line(env, i++) : (header->comment[parser->i_com++] = '\n');
}
