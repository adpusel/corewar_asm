#include "asm.h"

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
	return (i);
}

static int		check_last_line(t_asm *env, int i)
{
	i += ft_skip_spaces(env->parser.line + i);
	(env->parser.line[i] == '\0') ? env->parser.step = 2
		: env->parser.step = ERROR;
}

void			parse_comment(t_asm *env)
{
	static int	first = 0;
	int			i;
	char		cur;
	t_header	*header;

	i = 0;
	if (first == 0)
	{
		i = check_first_line(env);
		first = 1;
	}
	header = &(env->parser.header);
	while ((cur = env->parser.line[i++])
		&& cur != QUOTE_CHAR
		&& header->i_name <= COMMENT_LENGTH)
		header->prog_name[header->i_name++] = cur;
	if (cur == QUOTE_CHAR)
		check_last_line(env, i++);
}
