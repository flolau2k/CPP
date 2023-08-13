# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 09:51:54 by flauer            #+#    #+#              #
#    Updated: 2023/08/13 12:48:24 by flauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		megaphone

CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98

SRC =		megaphone.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "built $(NAME)"

clean:
	/bin/rm -rf $(NAME)

fclean: clean
	/bin/rm -rf $(NAME)

re:	fclean all

debug: CFLAGS += -g
debug: fclean all

.PHONY =	all clean fclean re