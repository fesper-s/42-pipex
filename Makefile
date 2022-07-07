NAME	= pipex

CFLAGS	= -Wall -Werror -Wextra

SRCS	=

OBJS	= $(SRCS:.c=.o)

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make -C ./libft
			cp ./libft/libft.a ./$(NAME)
			ar rcs $(NAME) $(OBJS)

all:		$(NANE)

clean:
			rm -f $(OBJS)
			make clean -C ./libft

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re
