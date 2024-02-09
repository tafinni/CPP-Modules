NAME	= base
CC		= c++
FLAGS	= -Wall -Wextra -Werror
SRC		= src/main.cpp src/Base.cpp

OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all