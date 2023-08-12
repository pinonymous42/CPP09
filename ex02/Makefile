# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kohei <kohei@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 16:33:59 by kohei             #+#    #+#              #
#    Updated: 2023/07/24 16:34:42 by kohei            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        :=  PmergeMe
CC			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
INCLUDE		:=	-Iincludes
VPATH		:=	srcs
SRCS		:=	main.cpp PmergeMe.cpp
OBJSDIR		:=	objs
OBJS		:=	$(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
RM			:=	rm -rf

all: $(NAME)

$(NAME): $(OBJSDIR) $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJSDIR)/%.o: %.cpp
	$(CC) $(INCLUDE) $(CXXFLAGS) -o $@ -c $<

objs:
	mkdir -p objs

clean:
	$(RM) $(OBJSDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
