# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfinni <tfinni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 14:06:12 by tfinni            #+#    #+#              #
#    Updated: 2023/10/31 14:06:13 by tfinni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	zombie
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC		=	main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all
