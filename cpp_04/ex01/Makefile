NAME = TheInkSpots

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp srcs/Animal.cpp srcs/Cat.cpp srcs/Dog.cpp srcs/Brain.cpp

$(NAME):
	@$(CC) $(SRCS) $(CFLAGS) -o $(NAME)
	@echo "$(NAME) compiled!"

all:	$(NAME)

clean:
	@rm $(NAME)
	@echo "$(NAME) cleaned!"

fclean:	clean

re:	fclean all
