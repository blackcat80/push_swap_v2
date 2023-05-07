# =============================== NAMES ====================================== #

NAME		= push_swap
HEADER  	= push_swap.h
INCLUDE		= -I ./includes/
SRC_DIR 	= ./src/

# ============================= COMPILATE RULES =============================== #

RM			= rm -rf
AR         	= ar -rcs
CFLAGS		= -Wall -Werror -Wextra #-fsanitize=address

# =========================== DIRECTORIES ==================================== #

OBJ_DIR 	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ))

# =========================== SOURCES ======================================== #

SRC			= main.c \
				input_check.c input_check_utils.c \
				initialization.c \
				stack.c \
				swap.c push.c rotate.c reverse_rotate.c \
				sort_tiny.c sort.c \
				position.c cost.c do_move.c \
				utils.c			

# =========================== BOLD COLORS ==================================== #

DEF_COLOR 	= \033[1;39m
GRAY 	   	= \033[1;90m
RED		   	= \033[1;91m
GREEN	    = \033[1;32m
YELLOW	    = \033[1;93m
BLUE 		= \033[1;94m
MAGENTA     = \033[1;95m
CYAN        = \033[1;96m
WHITE		= \033[1;97m
	
# =========================== BACKGROUND COLORS ============================ #

BG_Black	=\033[40m

# ========================== MAKE RULES ===================================== #

all: $(NAME)
	@echo "\n\n$(BG_Purple)$(GREEN)==== Project push_swap compiled! ==== ✅$(DEF_COLOR)$(BG_Black)\n"
	@touch $(NAME)

$(OBJ_DIR): $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HEADER)	
	@printf "$(YELLOW)\r $@$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJ_DIR)	
	@echo "\n$(CYAN)==== push_swap and objects files cleaned! ==== ✅$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "\n$(CYAN)==== push_swap executable file and name cleaned! ==== ✅$(DEF_COLOR)\n"

re: fclean all
	echo "\n$(GREEN)==== Cleaned and rebuilt everything for push_swap! ==== ✅$(DEF_COLOR)\n"

.PHONY: all clean fclean re 