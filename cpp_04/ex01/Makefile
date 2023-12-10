NAME = zoo

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp srcs/Animal.cpp srcs/Cat.cpp srcs/Dog.cpp srcs/Brain.cpp

OBJS = ${SRCS:.cpp=.o}

%.o: %.cpp
	@${CC} ${FLAG} -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) compiled"

all:	$(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "$(NAME) cleaned"

fclean:	clean
	rm -rf $(NAME)
	@echo "$(NAME) fcleaned"

re:	fclean all clean
