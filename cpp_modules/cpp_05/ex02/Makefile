NAME=ex02

OBJS = AForm.o Bureaucrat.o PresidentialPardonForm.o RobotomyRequestForm.o ShrubberyCreationForm.o main.o 
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
CXX = c++

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all