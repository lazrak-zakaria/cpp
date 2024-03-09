NAME=btc

CXX = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
OBJ = BitcoinExchange.o main.o

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re: fclean all
