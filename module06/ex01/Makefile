# Compiler and Flags
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Find all .cpp files under src/
SRC = $(wildcard $(SRC_DIR)/*.cpp)

# Generate corresponding .o files in obj/
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

# Target binary name
NAME = serializer
	
# Default target
all: $(NAME)

# Create obj directory if needed
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Link all object files into final executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .cpp → .o into obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -g -o $@

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild from scratch
re: fclean all

.PHONY: all clean fclean re