NAME = OrtoClax

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp srcs/Fixed.cpp

$(NAME):
	@$(CC) $(SRCS) $(CFLAGS) -o $(NAME)
	@echo "$(NAME) compiled!"

all:	$(NAME)

clean:
	@rm $(NAME)
	@echo "$(NAME) cleaned!"

fclean:	clean

re:	fclean all
