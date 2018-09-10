//
// Created by Adrien PUSEL on 8/23/18.
//

#ifndef CORWAR_GROUPE_A_FUNCTION_H
#define CORWAR_GROUPE_A_FUNCTION_H

/*
**	INIT
*/
void	init_asm(t_asm *env);

/*
**	CHECK_FILE
*/

void	check_file(t_asm *env);

/*
**	PARSER
*/

void			parse_file(t_asm *env);
void			parse_header(t_asm *env);
void			parse_name(t_asm *env);
void			parse_comment(t_asm *env);
void			parse_prog(t_asm *env);
void			parse_label(t_asm *env, char **line);
void			parse_op(t_asm *env, char **line);
void			parse_param(t_asm *env, char **line);
void			fill_param(t_asm *env, char **line, t_param *param, int type);
void			fill_label(t_asm *env);
void			asm_skip_spaces(char **line, char *escape_str);

/*
**	DATA TREATMENT
*/

void			treat_file(t_asm *env);
void			write_cor(t_asm *env);

/*
**	BYTE
*/

int32_t			little_endian(int32_t big);

/*
**	DEBUG
*/

void			print_instructions(t_asm *env);
void			print_instruction(t_instr *instr, int i);

/*
**	FREE
*/

void		free_asm(t_asm *env);

/*
**	ERROR
*/

void		handle_error(t_asm *env, int errcode);

#endif //CORWAR_GROUPE_A_FUNCTION_H
