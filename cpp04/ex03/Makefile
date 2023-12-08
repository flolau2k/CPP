NAME =		ex03_out

CC =		c++
CFLAGS =	-g -Wall -Wextra -Werror -Wshadow -std=c++98

OBJDIR =	obj

FILES =		main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
HEADER_F =	AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp \
						IMateriaSource.hpp MateriaSource.hpp

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
