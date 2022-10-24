# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 19:32:48 by nomargen          #+#    #+#              #
#    Updated: 2022/10/24 21:58:07 by nomargen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	bureaucrat

CC			=	c++

CFLAGS		=	-Wall -Werror -Wextra -std=c++98

SRC			=	main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

INC			=	Bureaucrat.h Form.h PresidentialPardonForm.h RobotomyRequestForm.h ShrubberyCreationForm.h

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