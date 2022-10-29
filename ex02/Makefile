# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 19:32:48 by nomargen          #+#    #+#              #
#    Updated: 2022/10/29 17:41:34 by nomargen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	dyncast

CC			=	c++

CFLAGS		=	-Wall -Werror -Wextra -std=c++98

SRC			=	main.cpp

INC			=	

RM			=	rm -rf

all:	$(NAME)

$(NAME): $(INC) $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re