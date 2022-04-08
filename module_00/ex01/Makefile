#
# Created by Diana catherine Salamanca leguizamon on 01-Feb-22.
#

NAME := phonebook

OBJ_DIR := obj/

SRC_DIR := src/

INC_DIR := includes/

FLAGS := -Wall -Wextra -Werror -std=c++98

SRC := Phonebook.cpp Contact.cpp main.cpp

SRC_PATH:= $(addprefix $(SRC_DIR), $(SRC))

OBJ := $(SRC_PATH:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $^ -o $@
	@echo "\033[38;5;10mphonebook executable successfully created.\n\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC_DIR)
	@mkdir -p $(dir $@)
	@$(CXX) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects were removed - clean."

fclean: clean
	@rm -f $(NAME)
	@echo "\033[38;5;81mphonebook executable was removed - fclean.\033[0m"

re: fclean all

.PHONY: all clean fclean re