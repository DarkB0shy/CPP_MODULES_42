NAME = ClapTrap

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp srcs/ClapTrap.cpp

$(NAME):
	@$(CC) $(SRCS) $(CFLAGS) -o $(NAME)
	@echo "$(NAME) compiled!"

all:	$(NAME)

clean:
	@rm $(NAME)
	@echo "$(NAME) cleaned!"

fclean:	clean

re:	fclean all
