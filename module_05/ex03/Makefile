#
# Created by Diana Salamanca on 16-Mar-22.
#

# Name of the program
NAME := intern

# Directories
OBJ_DIR := obj/
SRC_DIR := src/
INC_DIR := includes/

# Flags
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
IFLAGS := -I$(INC_DIR)
FLAGS += $(IFLAGS)

# Sources and objects
SRC := main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
SRC_PATH:= $(addprefix $(SRC_DIR), $(SRC))
OBJ := $(SRC_PATH:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
FILE_OUT = *_shrubbery

RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $^ -o $@
	@echo "\033[38;5;10m'$(NAME)' executable has been created.\n\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	@$(CXX) $(FLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ_DIR)
	@for i in $(FILE_OUT); do find . -name "$$i" -delete; done
	@echo "Objects were removed - clean."

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[38;5;81m'$(NAME)' executable was removed - fclean.\033[0m"

re: fclean all

.PHONY: all clean fclean re