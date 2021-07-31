PUSH_SWAP	=	push_swap
CHECKER		=	checker

SRCS_DIR	=	./sources/
SRCS_COM_LST=	eval_lst.c		ft_sort.c		stack_utils.c
SRCS_PS_LST	=	algo_utils.c	algorithms.c	ft_quicksort.c	push_swap.c
SRCS_CK_LST	=	checker.c

SRCS_COM	=	$(addprefix $(SRCS_DIR), $(SRCS_COM_LST))
SRCS_PS		=	$(addprefix $(SRCS_DIR), $(SRCS_PS_LST))
SRCS_CK		=	$(addprefix $(SRCS_DIR), $(SRCS_CK_LST))

OBJS_COM	=	$(SRCS_COM:.c=.o)
OBJS_PS		=	$(SRCS_PS:.c=.o)
OBJS_CK		=	$(SRCS_CK:.c=.o)

HDRS_DIR	=	./includes/
HDRS_LST	=	push_swap.h
HDRS		=	$(addprefix $(HDRS_DIR), $(HDRS_LST))

LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_HDRS	=	$(LIBFT_DIR)includes/

INCLUDES	=	-I $(HDRS_DIR) -I $(LIBFT_HDRS)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g

all : $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP) : $(LIBFT) $(OBJS_COM) $(OBJS_PS)
	@$(CC) $(CFLAGS) $(OBJS_PS) $(OBJS_COM) $(LIBFT) -o $@
	@echo " $(YELLOW)$@ $(GREEN)objects files created"
	@echo "$(BLUE)$@$(GREEN) created$(RESET)"

$(CHECKER) : $(LIBFT) $(OBJS_COM) $(OBJS_CK)
	@$(CC) $(CFLAGS) $(OBJS_CK) $(OBJS_COM) $(LIBFT) -o $@
	@echo " $(YELLOW)$@ $(GREEN)objects files created"
	@echo "$(BLUE)$@$(GREEN) created$(RESET)"

$(SRCS_DIR)%.o : $(SRCS_DIR)%.c $(HDRS)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS_COM) $(OBJS_PS) $(OBJS_CK)
	@echo "$(RED)removed $(YELLOW)$(PUSH_SWAP) & $(CHECKER) \
	$(RED)object files $(RESET)"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(PUSH_SWAP) $(CHECKER)
	@echo "$(RED)removed $(BLUE)$(PUSH_SWAP) $(CHECKER)$(RESET)"

re:	fclean all

.PHONY: all clean fclean re

RED		=	\033[00;31m
YELLOW	=	\033[03;33m
GREEN	=	\033[00;32m
BLUE	=	\033[01;36m
RESET	=	\033[0m
