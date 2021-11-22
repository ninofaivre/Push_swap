# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nino <nino@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 18:33:13 by nino              #+#    #+#              #
#    Updated: 2021/11/19 10:32:23 by nino             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

NAME = push_swap
BONUS = checker

CC = clang
CFLAGS = -Wall -Werror -Wextra

LIB_DIR = ft_printf
DIR_SRC = src/mandatory
DIR_BONUS_SRC = src/bonus
DIR_OBJ = .obj

INCLUDE = -Iinclude
BONUS_INCLUDE = -IGet-Next-Line/include

SRC = $(wildcard $(DIR_SRC)/*/*.c)
OBJ = $(addprefix $(DIR_OBJ)/, $(subst src/mandatory/operations/,, $(subst src/mandatory/main/,, $(subst src/mandatory/algo/,, $(SRC:.c=.o)))))
BONUS_SRC = $(wildcard $(DIR_BONUS_SRC)/*/*.c)
BONUS_OBJ = $(addprefix $(DIR_OBJ)/, $(subst src/bonus/operations/,, $(subst src/bonus/main/,, $(BONUS_SRC:.c=.o))))

GNL:
	@make -C Get-Next-Line DIR_OBJ=$(addprefix $(PWD)/, $(DIR_OBJ))

GNL_OBJ = $(DIR_OBJ)/get_next_line.o $(DIR_OBJ)/get_next_line_utils.o

$(DIR_OBJ)/%.o : $(DIR_BONUS_SRC)/*/%.c
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) $(BONUS_INCLUDE)

$(DIR_OBJ)/%.o : $(DIR_SRC)/*/%.c
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(BONUS): $(BONUS_OBJ)
	@make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(GNL_OBJ) -o $(BONUS) -L$(LIB_DIR) -l:libftprintf.a

$(NAME): $(OBJ)
	@make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) ./ft_printf/libftprintf.a

all: $(OBJ) $(NAME)

bonus: GNL $(BONUS_OBJ) $(BONUS)

clean:
	@make $@ -C $(LIB_DIR)
	@make $@ -C Get-Next-Line DIR_OBJ=$(addprefix $(PWD)/, $(DIR_OBJ))
	@rm -rf $(OBJ)
	@echo "removing $(OBJ)"
	@rm -rf $(BONUS_OBJ)
	@echo "removing $(BONUS_OBJ)"

fclean: clean
	@make $@ -C $(LIB_DIR)
	@rm -rf $(NAME)
	@echo "removing $(NAME)"
	@rm -rf $(BONUS)
	@echo "removing $(BONUS)"

re: fclean all

.PHONY: GNL all bonus clean re fclean
