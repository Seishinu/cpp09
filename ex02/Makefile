# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 15:29:04 by ynuiga            #+#    #+#              #
#    Updated: 2023/03/29 17:13:21 by ynuiga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe 

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp PmergeMe.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) -o $(NAME) $(FLAGS)

clean:
	@rm -f $(NAME)

fclean:	clean

re : fclean all