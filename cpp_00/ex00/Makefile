NAME = Megaphone

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = .

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

$(NAME):
	@$(CC) $(SRCS) $(CFLAGS) -o $(NAME)
	@echo "$(NAME) compiled!"

all:	$(NAME)

clean:
	@rm $(NAME)
	@echo "$(NAME) cleaned!"

fclean:	clean

re:	fclean all
