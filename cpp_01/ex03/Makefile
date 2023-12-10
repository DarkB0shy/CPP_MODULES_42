NAME = humans

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp srcs/HumanA.cpp  srcs/HumanB.cpp	srcs/Weapon.cpp

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
