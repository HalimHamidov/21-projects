# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apearl <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 23:28:51 by apearl            #+#    #+#              #
#    Updated: 2019/10/13 16:04:56 by bkayleen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./src/*.c
OBJ = ./src/*.o
HDR = ./src/
FLAG = -Wall -Wextra -Werror

LIBFT = libft/

all:	$(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAG) -o $(NAME) $(SRC) -I $(HDR) -L. libft/libft.a
   	
clean:
	@rm -f $(OBJ)
	make -C $(LIBFT) fclean

fclean: clean
	@rm -f $(NAME)
	make -C $(LIBFT) fclean 

re: fclean all

.PHONY: all, clean, fclean, re
