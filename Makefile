# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfaivre <nfaivre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 18:33:13 by nino              #+#    #+#              #
#    Updated: 2021/12/02 11:33:43 by nfaivre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

NAME = push_swap
BONUS = checker

CC = clang
CFLAGS = -Wall -Werror -Wextra

DIR_SRC = src/mandatory
DIR_BONUS_SRC = src/bonus
DIR_OBJ = .obj

INCLUDE = -Iinclude
BONUS_INCLUDE = -IGet-Next-Line/include

SRC = $(wildcard $(DIR_SRC)/*/*.c)
OBJ = $(addprefix $(DIR_OBJ)/, $(notdir $(SRC:.c=.o)))
BONUS_SRC = $(wildcard $(DIR_BONUS_SRC)/*/*.c)
BONUS_OBJ = $(addprefix $(DIR_OBJ)/, $(notdir $(BONUS_SRC:.c=.o)))
GNL_OBJ = $(DIR_OBJ)/get_next_line.o $(DIR_OBJ)/get_next_line_utils.o

mkdir_DIR_OBJ:
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o : $(DIR_BONUS_SRC)/*/%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) $(BONUS_INCLUDE)

$(DIR_OBJ)/%.o : $(DIR_SRC)/*/%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(BONUS):
	make -C ft_printf
	@make -C Get-Next-Line DIR_OBJ=$(addprefix $(PWD)/, $(DIR_OBJ))
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(GNL_OBJ) -o $(BONUS) -Lft_printf -l:libftprintf.a

$(NAME):
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -Lft_printf -l:libftprintf.a

all: mkdir_DIR_OBJ $(OBJ) $(NAME)

bonus: mkdir_DIR_OBJ $(BONUS_OBJ) $(BONUS)

clean:
	make $@ -C ft_printf
	make $@ -C Get-Next-Line DIR_OBJ=$(addprefix $(PWD)/, $(DIR_OBJ))
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)

fclean: clean
	make $@ -C ft_printf
	make $@ -C Get-Next-Line DIR_OBJ=$(addprefix $(PWD)/, $(DIR_OBJ))
	rm -f $(NAME)
	rm -f $(BONUS)
	rm -rf $(DIR_OBJ)

re: fclean all

.PHONY: all bonus clean fclean re
