NAME	= libft.a

CFLAGS	= -Wall -Werror -Wextra

SRCS	= $(wildcard *.c)

SRCS_B	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		  ft_lstmap_bonus.c

OBJS	= $(SRCS:.c=.o)

OBJS_B	= $(SRCS_B:.c=.o)

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

bonus:		$(OBJS_B)
			ar rc $(NAME) $(OBJS_B)
			ranlib $(NAME)

all:		$(NAME)

clean:
			rm -f $(OBJS) $(OBJS_B)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	bonus all clean fclean re
