# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 12:32:54 by tfinni            #+#    #+#              #
#    Updated: 2023/11/18 12:32:55 by tfinni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Animal
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC		=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all