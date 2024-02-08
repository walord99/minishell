FILES			= 	main.c 
SRC_DIR			= 	src
OBJ_DIR			= 	obj
SRC				= 	$(addprefix src/, $(FILES))
OBJ 			= 	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
CC				=	gcc

NAME			= 	minishell
HEADER_DIR		= 	include

LIBS			=	-lreadline

INCLUDES		= 	-I$(HEADER_DIR)
#L_DEBUG		=	-fsanitize=address -fno-omit-frame-pointer
#L_DEBUG		=	-fsanitize=address
ERROR_FLAGS 	= 	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(L_DEBUG) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CC_DEBUG) $(INCLUDES) $(ERROR_FLAGS) -c $< -o $@ -g

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) 

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: clean all                         

.PHONY: all clean fclean re
