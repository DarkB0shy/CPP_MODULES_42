NAME = PhoneBook

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS = main.cpp

$(NAME):
	@$(CC) $(SRCS) $(CFLAGS) -o $(NAME)
	@echo "$(NAME) compiled!"

all:	$(NAME)

clean:
	@rm $(NAME)
	@echo "$(NAME) cleaned!"

fclean:	clean

re:	fclean all
