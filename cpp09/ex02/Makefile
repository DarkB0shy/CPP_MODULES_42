NAME = PMergeMe

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -O0

SANITIZE = -fsanitize=address -fsanitize=leak -fsanitize=undefined

SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

%.o: %.cpp
	${CC} ${FLAG} -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled!"

all:	$(NAME)

clean:
	rm -rf $(OBJS)
	@echo "$(NAME) cleaned"

fclean:clean
	rm -rf $(NAME)
	@echo "$(NAME) fcleaned"

re:	fclean all clean