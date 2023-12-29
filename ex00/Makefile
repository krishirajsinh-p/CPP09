# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 03:03:55 by kpuwar            #+#    #+#              #
#    Updated: 2023/12/29 03:04:20 by kpuwar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=  btc

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

CLASSES		= BitcoinExchange
INCLUDES	= $(addsuffix .hpp, $(CLASSES))
SRCS		= main.cpp $(addsuffix .cpp, $(CLASSES))
OBJS		= ${SRCS:.cpp=.o}

RM			= rm -rf

$(NAME): $(SRCS) $(OBJS) $(INCLUDES)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
