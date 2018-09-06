# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 14:39:22 by plamusse          #+#    #+#              #
#    Updated: 2018/09/06 15:56:46 by plamusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

# directories
SRC_DIR		= ./src
INC_DIR		= ./includes
OBJ_DIR		= ./obj

# src / obj files

SRC = ft_putendl_fd.c\
	  check_char_into_str.c\
	  ft_atoi.c\
	  ft_isdigit.c\
	  ft_isspace.c\
	  ft_strlen.c\
	  ft_strcmp.c\
	  ft_strclen.c\
	  ft_strdup.c\
	  ft_strjoin.c\
	  ft_strnew.c\
	  ft_strsub.c\
	  ft_strchr.c\
	  ft_strnequ.c\
	  ft_skip_spaces.c\
	  ft_dup_memory.c\
	  ft_memdel.c\
	  ft_memcpy.c\
	  ft_memset.c\
	  print_memory.c\
	  get_next_line.c\
	  dll_add.c \
      dll_construct.c \
      dll_drop_index.c \
      dll_drop_link.c \
      dll_func.c \


OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# compiler and flags
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(INC_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
