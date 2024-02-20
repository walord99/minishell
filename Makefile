# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bplante <bplante@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 08:17:58 by ldufour           #+#    #+#              #
#    Updated: 2024/02/20 14:37:19 by bplante          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = minishell
CC              = gcc
CFLAGS          = -g #-Wall -Wextra -Werror
RM              = rm -rf
LIBFT           = $(LIBFT_DIR)/libft.a
SRC_DIR         = src
INC_DIR         = includes
LIBFT_DIR       = lib/libft
READLINE_DIR    = lib/readline-8.1
READLINE_LIB    = $(READLINE_DIR)/libreadline.a
READLINE_INC    = -I$(READLINE_DIR)/include
READLINE_URL    = ftp://ftp.gnu.org/gnu/readline/readline-8.1.tar.gz

INC             = -I$(INC_DIR) -I$(LIBFT_DIR) $(READLINE_INC)
LIBS            = -lncurses -L$(READLINE_DIR) -lreadline -lhistory

SRC = $(SRC_DIR)/main.c  $(SRC_DIR)/prompt.c $(SRC_DIR)/builtin/pwd.c\
      $(SRC_DIR)/utils.c $(SRC_DIR)/builtin/cd.c  $(SRC_DIR)/env_utils.c\
      $(SRC_DIR)/builtin/echo.c  $(SRC_DIR)/builtin/env.c\
	  $(SRC_DIR)/tokenizer/redirections.c $(SRC_DIR)/tokenizer/syntax.c $(SRC_DIR)/tokenizer/syntax_error.c\
	  $(SRC_DIR)/tokenizer/quotes_handler.c $(SRC_DIR)/child_process.c\
      $(SRC_DIR)/builtin/built_exit.c $(SRC_DIR)/signals.c\
	  $(SRC_DIR)/builtin/export.c $(SRC_DIR)/builtin/unset.c $(SRC_DIR)/builtin/builtin_execution.c\

OBJ = $(SRC:.c=.o)

LOGO_1 =             ▄▄▄▄███▄▄▄▄    ▄█  ███▄▄▄▄    ▄█     ▄████████    ▄█    █▄       ▄████████  ▄█        ▄█               \n
LOGO_2 =           ▄██▀▀▀███▀▀▀██▄ ███  ███▀▀▀██▄ ███    ███    ███   ███    ███     ███    ███ ███       ███               \n
LOGO_3 =           ███   ███   ███ ███▌ ███   ███ ███▌   ███    █▀    ███    ███     ███    █▀  ███       ███               \n
LOGO_4 =           ███   ███   ███ ███▌ ███   ███ ███▌   ███         ▄███▄▄▄▄███▄▄  ▄███▄▄▄     ███       ███               \n
LOGO_5 =           ███   ███   ███ ███▌ ███   ███ ███▌ ▀███████████ ▀▀███▀▀▀▀███▀  ▀▀███▀▀▀     ███       ███               \n
LOGO_6 =           ███   ███   ███ ███  ███   ███ ███           ███   ███    ███     ███    █▄  ███       ███               \n
LOGO_7 =		   ███   ███   ███ ███  ███   ███ ███     ▄█    ███   ███    ███     ███    ███ ███▌    ▄ ███▌    ▄         \n
LOGO_8 =            ▀█   ███   █▀  █▀    ▀█   █▀  █▀    ▄████████▀    ███    █▀      ██████████ █████▄▄██ █████▄▄██         \n

DISPLAY_LOGOS = printf "\n $(BLUE) %0s $(ART_NAME_1) $(ART_NAME_2) $(ART_NAME_3) $(ART_NAME_4) $(ART_NAME_5) $(ART_NAME_6) $(ART_NAME_7) %0s $(ART_NAME_8) $(END)\n"

all: install $(NAME)

$(NAME):	$(OBJ) $(LIBFT) $(READLINE_LIB)
	@$(DISPLAY_LOGOS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(INC)
	@echo $(CUT) $(CUT) 
	@echo $(BOLD)$(L_PURPLE) Notre minishell est plus mignon qu’un vrai shell  💪💥 $(RESET)	

$(READLINE_LIB): $(READLINE_DIR)
	@if [ ! -f "$@" ]; then \
		echo $(BOLD)$(PINK)"Building Readline 8.1 library..."$(MINT); \
		cd $(READLINE_DIR) && ./configure --prefix=$(CURDIR) && make; \
		echo $(BOLD)$(GREEN)"Readline library built successfully"$(RESET); \
	else \
		echo $(BOLD)$(PINK)"nothing to be done for all."$(RESET); \
	fi

$(READLINE_DIR):
	@mkdir -p $(READLINE_DIR)
	@test -f $(READLINE_DIR)/libreadline.a || { curl -L $(READLINE_URL) | tar xz -C $(READLINE_DIR) --strip-components=1; }
	@echo $(BOLD)$(GREEN) ✨ Readline 8.1 ✨ downloaded and extracted successfully. 💪💥 $(RESET)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)
	@echo "Compiled $<"

readline-8.1_EXISTS := $(wildcard lib/readline-8.1)

install: $(READLINE_LIB)
	
norm:
	@echo $(BOLD)$(PINK)" Mandatory part!"$(MINT)
	@norminette $(SRC) $(INC_DIR)
	@echo $(BOLD)$(PINK)" Bonus part!"$(MINT)
	@norminette $(BONUS_SRC)

clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ)
	@echo $(BOLD)$(GREEN) Cleaned objects and executables! ... 🧹🗑️$(RESET)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) 
	@echo $(BOLD)$(L_PURPLE) ✨minishell✨ $(PINK)All cleaned up! ....🧹🗑️$(RESET)

re: fclean all

.PHONY: all clean fclean re install
