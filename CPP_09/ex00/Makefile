NAME	= btc
CC		= c++
FLAGS	= -Wall -Wextra -Werror
SRC		= main.cpp src/BitcoinExchange.cpp src/validation.cpp src/handleFiles.cpp

OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all