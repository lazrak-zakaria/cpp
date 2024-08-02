NAME=ex03
OBJS = ./cpp/AMateria.o ./cpp/Character.o ./cpp/Cure.o ./cpp/Ice.o \
			./cpp/MateriaSource.o ./cpp/IMateriaSource.o ./cpp/ICharacter.o ./main.o
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