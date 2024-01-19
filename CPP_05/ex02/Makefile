NAME	= Bureaucrat
CC		= c++
FLAGS	= -Wall -Wextra -Werror
SRC		= \
		src/main.cpp \
		src/Bureaucrat.cpp \
		src/AForm.cpp \
		src/PresidentialPardonForm.cpp \
		src/RobotomyRequestForm.cpp \
		src/ShrubberyCreationForm.cpp

OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all