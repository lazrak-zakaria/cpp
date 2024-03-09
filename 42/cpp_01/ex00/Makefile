NAME = ex00
OBJS=Zombie.o main.o newZombie.o randomChump.o
CPPFLAGS = -std=c++98 -Wall -Werror -Wextra 
CXX = c++

all : $(NAME)

$(NAME) : $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
