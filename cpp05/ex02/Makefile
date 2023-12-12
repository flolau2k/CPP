NAME =		a.out

CC =		c++
CFLAGS =	-g -Wall -Wextra -Werror -std=c++98

OBJDIR =	obj

FILES =		main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
					RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
HEADER_F =	Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp \
						RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

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
