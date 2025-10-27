# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 15:40:04 by kosakats          #+#    #+#              #
#    Updated: 2025/10/27 19:52:39 by kosakats         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude

SRCS = src/main.cpp src/Bureaucrat.cpp src/AForm.cpp \
		src/PresidentialPardonForm.cpp \
		src/ShrubberyCreationForm.cpp \
		src/RobotomyRequestForm.cpp \
		src/Intern.cpp
		

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re