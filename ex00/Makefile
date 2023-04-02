# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 09:16:03 by ynuiga            #+#    #+#              #
#    Updated: 2023/03/28 18:12:20 by ynuiga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc 

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp BitcoinExchange.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) -o $(NAME) $(FLAGS)

clean:
	@rm -f $(NAME)

fclean:	clean

re : fclean all
