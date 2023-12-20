NAME =		a.out

CC =		c++
CFLAGS =	-g -Wall -Wextra -Werror -std=c++98

OBJDIR =	obj

FILES =		ScalarConverter.cpp main.cpp
HEADER_F =	ScalarConverter.hpp

SRC =		$(FILES)
OBJ =		$(addprefix $(OBJDIR)/, $(FILES:%.cpp=%.o))
HEADERS =	$(HEADER_F)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "built $(NAME)"

$(OBJDIR)/%.o: %.cpp $(HEADERS) | $(OBJDIR)
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
