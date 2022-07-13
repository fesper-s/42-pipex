NAME	= pipex.a

CFLAGS	= -Wall -Werror -Wextra

SRCS	= pipex.c

OBJS	= $(SRCS:.c=.o)

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./include

$(NAME):	$(OBJS)
			make -C ./libft
			cp ./libft/libft.a ./$(NAME)
			ar rcs $(NAME) $(OBJS)
			cc $(NAME) -o pipex

all:		$(NANE)

clean:
			rm -f $(OBJS)
			make clean -C ./libft

fclean:		clean
			rm -f $(NAME) pipex
			make fclean -C ./libft

re:			fclean all
			make re -C ./libft

.PHONY:		all clean fclean re
