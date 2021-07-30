PUSH_SWAP	=	push_swap
CHECKER		=	checker

SRCS_DIR	=	./sources/
SRCS_COM_LST=	algorithms.c eval_lst.c ft_sort.c ft_quicksort.c\
				algo_utils.c
SRCS_PS_LST	=	push_swap.c
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
	$(CC) $(CFLAGS) $(OBJS_PS) $(OBJS_COM) $(LIBFT) -o $@

$(CHECKER) : $(LIBFT) $(OBJS_COM) $(OBJS_CK)
	$(CC) $(CFLAGS) $(OBJS_CK) $(OBJS_COM) $(LIBFT) -o $@

$(SRCS_DIR)%.o : $(SRCS_DIR)%.c $(HDRS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS_COM) $(OBJS_PS) $(OBJS_CK)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(PUSH_SWAP) $(CHECKER)

re:	fclean all

.PHONY: all clean fclean re
	