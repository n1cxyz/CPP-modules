NAME		= form
CXX			= c++
BIN			= bin
INCLUDES	= -I./include
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
SRC			= src/main.cpp src/Bureaucrat.cpp src/Form.cpp src/ShrubberyCreationForm.cpp src/RobotomyRequestForm.cpp src/PresidentialPardonForm.cpp src/Intern.cpp
OBJS		= $(SRC:src/%c=$(BIN)/%o)
RM			= rm -rf

all: $(NAME)

$(NAME): ${BIN} ${OBJS}
	${CXX} ${CXXFLAGS} $(INCLUDES) ${OBJS} -o ${NAME}

$(BIN)/%o: src/%c
	${CXX} ${CXXFLAGS} -c $< ${INCLUDES} -o $@

$(BIN):
	mkdir -p $(BIN)

clean:
	$(RM) $(BIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean