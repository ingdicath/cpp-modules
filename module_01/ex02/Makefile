#
# Created by Diana catherine Salamanca leguizamon on 10-Feb-22.
#

NAME := brain

OBJ_DIR := obj/

FLAGS := -Wall -Wextra -Werror -std=c++98

SRC := main.cpp

OBJ := $(SRC:%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $^ -o $@
	@echo "\033[38;5;10mbrain executable successfully created.\n\033[0m"

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects were removed - clean."

fclean: clean
	@rm -f $(NAME)
	@echo "\033[38;5;81mbrain executable was removed - fclean.\033[0m"

re: fclean all

.PHONY: all clean fclean re