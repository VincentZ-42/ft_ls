# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzhao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/28 16:24:40 by vzhao             #+#    #+#              #
#    Updated: 2019/10/03 12:34:47 by vzhao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

INC = srcs
LIB = libft

FILES = *.c

SRCS = $(patsubst %, $(INC)/%, $(FILES))

INCS = -I $(INC) -I $(LIB)
FLAGS = -Wall -Wextra -Werror $(INCS) -L./libft/ -lft

all: $(NAME)

$(NAME):
	@Make -C $(LIB)
	@gcc $(FLAGS) -o $(NAME) $(SRCS)

clean:
	@make clean -C $(LIB)

fclean: clean
	@make fclean -C $(LIB)
	@/bin/rm -f $(NAME)

re: fclean all

test: re
	@echo "---------------------------------"
	./ft_ls -l
	@echo "---------------------------------"

.PHONY: clean fclean re all
