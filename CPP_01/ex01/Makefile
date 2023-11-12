# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 14:06:31 by tfinni            #+#    #+#              #
#    Updated: 2023/10/31 14:34:18 by tfinni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	zombieHorde
SRC		=	main.cpp Zombie.cpp zombieHorde.cpp
OBJ		=	$(SRC:.cpp=.o)
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all
