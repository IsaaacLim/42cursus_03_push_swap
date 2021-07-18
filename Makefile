NAME		=	push_swap

SRCS		=	algorithms.c push_swap.c lst_evaluate.c ft_sort.c quicksort.c\
				ft_sort_radix.c

OBJS		=	$(SRCS:.c=.o)

HDRS_DIR	=	./includes/
HDRS_LST	=	push_swap.h
HDRS		=	$(addprefix $(HDRS_DIR), $(HDRS_LST))

LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_HDRS	=	$(LIBFT_DIR)includes/

INCLUDES	=	-I $(HDRS_DIR) -I $(LIBFT_HDRS)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

%.o : %.c $(HDRS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
	