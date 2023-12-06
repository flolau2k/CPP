NAME =		ex00_out

CC =		c++
CFLAGS =	-g -Wall -Wextra -Werror -Wshadow -std=c++98

INCLUDES =	-Iinclude

OBJDIR =	obj

FILES =		main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
HEADER_F =	Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.cpp

SRC =		$(FILES)
OBJ =		$(addprefix $(OBJDIR)/, $(FILES:%.cpp=%.o))
HEADERS =	$(HEADER_F)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -o $(NAME)
	@echo "built $(NAME)"

$(OBJDIR)/%.o: %.cpp $(HEADERS) | $(OBJDIR)
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
