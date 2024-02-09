NAME	= convert
CC		= c++
FLAGS	= -Wall -Wextra -Werror
SRC		= main.cpp ScalarConverter.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAG) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all