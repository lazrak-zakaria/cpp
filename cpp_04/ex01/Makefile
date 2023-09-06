NAME=ex01
OBJS = Animal.o Brain.o Cat.o Dog.o main.o 
CXX= c++
CPPFLAGS= -std=c++98 -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all