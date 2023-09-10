NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
OBJ_DIR = objs/
SRC_DIR = srcs/
INCLUDE = -L ./libft -lft
INCS	= -I ./includes/

SRC =	main.c \
		error_handling.c \
		utils.c \
		stack_utils.c \
		sort.c \
		sort_big.c \
		sort_utils.c \
		do_best_move.c \
		do_best_move_utils.c \
		swap_operations.c \
		push_operations.c \
		rotate_operations.c \
		reverse_rotate_operations.c \

SRCS	= $(addprefix $(SRC_DIR), $(SRC))

OBJ		= $(SRC:.c=.o)
OBJS 	= $(addprefix $(OBJ_DIR), $(OBJ))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCS)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(OBJS)
		make -C $(LIBFT_DIR)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

clean:
		rm -rf $(OBJ_DIR)
		@cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
		$(RM) $(NAME)
		@cd $(LIBFT_DIR) && $(MAKE) fclean

# TESTER
GIT_VISUALIZER	= git clone https://github.com/o-reo/push_swap_visualizer.git _push_swap_visualizer
VISUALIZER		= ./_push_swap_visualizer
OPEN_VISUALIZER	= ./_push_swap_visualizer/build/bin/visualizer
CREAR			= clear

download_visualizer :
	$(GIT_VISUALIZER) && $(CREAR)
	mkdir $(VISUALIZER)/build
	cd $(VISUALIZER)/build && cmake .. && $(CREAR)
	cd $(VISUALIZER)/build && make && $(CREAR)
	make re && $(CREAR)
	$(OPEN_VISUALIZER) && $(CREAR)
	$(RM) imgui.ini && $(RM_RF) $(VISUALIZER) && make fclean && $(CREAR)

GIT_LEAK_TESTER	= git clone https://github.com/IDC87/push_swap_leak_tester.git _push_swap_leak_tester
LEAK_TESTER		= ./_push_swap_leak_tester
LEAK_TESTER_SH	= test_leaks.sh
RM_RF			= rm -rf

download_leak_tester :
	$(GIT_LEAK_TESTER) && clear
	cd $(LEAK_TESTER) && mv $(LEAK_TESTER_SH) ../$(LEAK_TESTER_SH)
	make re
#	make bonus && clear
	bash $(LEAK_TESTER_SH)
	$(RM) $(LEAK_TESTER_SH) && $(RM_RF) $(LEAK_TESTER) && make fclean

re: clean all

.PHONY: all clean fclean re
