# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 11:18:23 by flauer            #+#    #+#              #
#    Updated: 2023/08/18 11:19:33 by flauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ex00_out

CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98

INCLUDES =	-Iinclude

OBJDIR =	obj
SRCDIR =	src
INCDIR =	include

FILES =		main.cpp Fixed.cpp
HEADER_F =	Fixed.hpp

SRC =		$(addprefix $(SRCDIR)/, $(FILES))
OBJ =		$(addprefix $(OBJDIR)/, $(FILES:%.cpp=%.o))
HEADERS =	$(addprefix $(INCDIR)/, $(HEADER_F))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -o $(NAME)
	@echo "built $(NAME)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	/bin/rm -rf $(OBJDIR)
	/bin/rm -rf $(NAME).dSYM

fclean: clean
	/bin/rm -rf $(NAME)

re:	fclean all

debug: CFLAGS += -g
debug: fclean all

.PHONY =	all clean fclean re
