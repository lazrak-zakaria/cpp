NAME = ex03
OBJS= HumanA.o HumanB.o Weapon.o main.o
CPPFLAGS = -std=c++98 -Wall -Werror -Wextra #-fsanitize=address
CXX = c++

all : $(NAME)

$(NAME) : $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
