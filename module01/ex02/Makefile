NAME		= brain
CXX			= c++
BIN			= bin
INCLUDES	= -I./include
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
SRC			= main.cpp
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