NAME	= Bureaucrat
CC		= c++
FLAGS	= -Wall -Wextra -Werror
SRC		= \
		main.cpp \
		Bureaucrat.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all