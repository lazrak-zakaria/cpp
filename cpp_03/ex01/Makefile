NAME=ex01
CPPFLAGS= -std=c++98 -Wall -Werror -Wextra
CXX= c++
OBJS=  ClapTrap.o ScavTrap.o main.o  

all : $(NAME)


$(NAME) : $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
