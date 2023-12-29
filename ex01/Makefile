# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 02:57:35 by kpuwar            #+#    #+#              #
#    Updated: 2023/12/29 03:04:32 by kpuwar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=  RPN

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

CLASSES		= RPN
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
