NAME	=	libft.a

SRCS_OTH	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c  \
			ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
			ft_strlcpy.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
BONUS 	=	ft_lstiter.c  ft_lstmap.c  ft_lstsize.c
BOBJS	=	$(BONUS:.c=.o)

SRCS_DIR	=	./sources/
SRCS_LST	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_putstr_fd.c ft_strlen.c
SRCS_B_LST	=	ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstnew_bonus.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LST) $(SRCS_B_LST))

OBJS		= 	$(SRCS:.c=.o)

HDRS_DIR	=	./includes/
HRDS_LST	=	libft.h
HDRS		=	$(addprefix $(HDRS_DIR), $(HRDS_LST))

INCLUDES	=	-I $(HDRS_DIR)

CC		=	gcc
CFLAGS	=	-c -Wall -Wextra -Werror -g

all:		$(NAME) 

$(NAME):	$(OBJS)
	ar rcs $@ $^

$(SRCS_DIR)%.o : $(SRCS_DIR)%.c $(HDRS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

#bonus:		$(OBJS) $(BOBJS)
#		ar rcs $(NAME) $(OBJS) $(BOBJS)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
