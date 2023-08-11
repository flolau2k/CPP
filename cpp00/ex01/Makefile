# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 09:51:54 by flauer            #+#    #+#              #
#    Updated: 2023/08/11 15:30:47 by flauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		phonebook

CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98

INCLUDES =	-Iinclude -pthread

OBJDIR =	obj
SRCDIR =	src
INCDIR =	include

FILES =		phonebook.cpp contact.cpp main.cpp
HEADER_F =	phonebook.hpp contact.hpp

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

fclean: clean
	/bin/rm -rf $(NAME)

re:	fclean all

debug: CFLAGS += -g
debug: fclean all

.PHONY =	all clean fclean re