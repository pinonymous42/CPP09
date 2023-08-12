# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kohei <kohei@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 10:32:44 by kohei             #+#    #+#              #
#    Updated: 2023/08/04 10:32:45 by kohei            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        :=  btc
CC			:=	c++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
INCLUDE		:=	-Iincludes
VPATH		:=	srcs
SRCS		:=	main.cpp BitcoinExchange.cpp
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
