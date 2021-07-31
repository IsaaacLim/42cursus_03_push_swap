NAME	=	libft.a

SRCS_DIR	=	./sources/
SRCS_LST	=	ft_atoi.c			ft_bzero.c			ft_calloc.c			\
				ft_lstadd_back.c	ft_lstadd_front.c	ft_lstlast.c 		\
				ft_lstsize.c 		ft_putchar_fd.c		ft_putnbr_fd.c 		\
				ft_putstr_fd.c 		ft_strchr.c 		ft_strdup.c			\
				ft_strjoin.c		ft_strlen.c 		ft_strncmp.c		\
				ft_strnstr.c		ft_substr.c
SRCS_B_LST	=	ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstnew_bonus.c
GNL_LST		=	get_next_line.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LST) $(SRCS_B_LST) $(GNL_LST))

OBJS		= 	$(SRCS:.c=.o)

HDRS_DIR	=	./includes/
HRDS_LST	=	libft.h get_next_line.h
HDRS		=	$(addprefix $(HDRS_DIR), $(HRDS_LST))

INCLUDES	=	-I $(HDRS_DIR)

CC		=	gcc
CFLAGS	=	-c -Wall -Wextra -Werror -g

all:		$(NAME) 

$(NAME):	$(OBJS)
	@ar rcs $@ $^
	@echo " $(YELLOW)$(NAME) $(GREEN)object files created"
	@echo "$(BLUE)$(NAME)$(GREEN) created$(RESET)"

$(SRCS_DIR)%.o : $(SRCS_DIR)%.c $(HDRS)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@rm -f $(OBJS)
	@echo "$(RED)removed $(YELLOW)$(NAME) $(RED)object files $(RESET)"

fclean:		clean
	@rm -f $(NAME)
	@echo "$(RED)removed $(BLUE)$(NAME)$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re bonus

RED		=	\033[00;31m
YELLOW	=	\033[03;33m
GREEN	=	\033[00;32m
BLUE	=	\033[01;36m
RESET	=	\033[0m
