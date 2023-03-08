##
## EPITECH PROJECT, 2023
## olympecpp
## File description:
## Makefile
##

SRC_DIR = Sources

BUILD_DIR = Build

SRC += $(SRC_DIR)/StringUtils.cpp

OBJ = $(SRC:%.cpp=$(BUILD_DIR)/%.o)

NAME = libolympe.a

CXXFLAGS += -Wall -Wextra -Werror -W -std=c++20 -I./Include

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) \
	&& $(ECHO) $(BOLD) $(GREEN)"► OLYMPE-LIB BUILD SUCCESS !"$(DEFAULT) \
	|| ($(ECHO) $(BOLD) $(RED)"► OLYMPE-LIB BUILD FAILED"$(DEFAULT) && exit 1)

clean:
	@rm -f $(OBJ)
	@rm -f *~

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(BUILD_DIR)/%.o:%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] " \
	$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) \
	$(BOLD) $< | rev | cut -d'/' -f 1 | rev && $(ECHO) -n $(DEFAULT)

.PHONY: all clean fclean re

ECHO       =       /bin/echo -e
DEFAULT    =       "\033[00m"

BOLD       =       "\e[1m"
RED        =       "\e[31m"
GREEN      =       "\e[32m"
WHITE      =       "\e[1;37m"