NAME = harlFilter
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = Animal.cpp main.cpp Animals.cpp Brain.cpp

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re