# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 14:39:22 by plamusse          #+#    #+#              #
#    Updated: 2018/08/28 13:00:28 by plamusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# programs
NAME		= asm

# directories
SRC_DIR		= ./src
INC_DIR		= ./includes
OBJ_DIR		= ./obj
LIB_DIR		= ./libft

# src / obj files

SRC			=	main.c \
				handle_error.c

OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


# compiler and flags
CC			= gcc
CFLAGS		= -g -Wall -Werror -Wextra  -g

# libraries
L_FT		= $(LIB_DIR)
LIB_LNK		= -L $(L_FT) -lft
LIB_INC		= $(L_FT)/ft_library_headerd.h

all: libft $(NAME)

libft:
	@$(MAKE) -C $(L_FT)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INC_DIR) $(LIB_INC)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_DIR) -I $(LIB_INC)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB_LNK)

clean:
	@$(MAKE) fclean -C $(L_FT)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf *.dSYM

re:
	@$(MAKE) fclean
	@$(MAKE) all
