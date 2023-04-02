# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 18:12:33 by ynuiga            #+#    #+#              #
#    Updated: 2023/03/29 14:38:09 by ynuiga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN 

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp RPN.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) -o $(NAME) $(FLAGS)

clean:
	@rm -f $(NAME)

fclean:	clean

re : fclean all