# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 18:42:10 by tfinni            #+#    #+#              #
#    Updated: 2023/11/06 18:42:11 by tfinni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ScavTrap
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC		=	main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all