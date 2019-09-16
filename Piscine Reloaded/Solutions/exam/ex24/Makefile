# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apearl <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 05:51:55 by apearl            #+#    #+#              #
#    Updated: 2019/09/15 05:56:20 by apearl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=srcs/*.c
OBJECTS=*.o
HEADERS=includes

all: make_lib

make_lib: 
	gcc -I$(HEADERS) -c $(SRCS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

flcean: clean
	/bin/rm -f $(NAME)

re: fclean all


