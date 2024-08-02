NAME = phonebook
OBJS = Contact.o PhoneBook.o main.o 
CPPFLAGS = -std=c++98 -Wall -Werror -Wextra 
CXX = c++

all: $(NAME)

$(NAME) : $(OBJS)
		c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: fclean all
