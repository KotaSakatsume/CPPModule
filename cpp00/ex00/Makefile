NAME		= megaphone
SRCS		=  megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

.PHONY: clean
clean:
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
