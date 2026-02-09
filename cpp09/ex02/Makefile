NAME        = PmergeMe
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS        = src/main.cpp src/PmergeMe.cpp
OBJS        = $(SRCS:.cpp=.o)
INCLUDES    = -I include

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re