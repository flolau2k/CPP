# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 14:17:38 by flauer            #+#    #+#              #
#    Updated: 2023/08/15 16:28:26 by flauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		ex04_out

CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98

OBJDIR =	obj

FILES =		main.cpp

OBJ =		$(addprefix $(OBJDIR)/, $(FILES:%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "built $(NAME)"

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

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
