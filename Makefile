NAME	= pipex.a

CFLAGS	= -Wall -Werror -Wextra

SRCS	= ./srcs/pipex.c ./srcs/pipex_utils.c ./srcs/error.c

OBJS	= $(SRCS:.c=.o)

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./include

$(NAME):	$(OBJS)
			make -C ./libft
			cp ./libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJS)
			cc $(NAME) -o ./pipex

all:		$(NAME)

clean:
			rm -f $(OBJS)
			make clean -C ./libft

fclean:		clean
			rm -f $(NAME) ./pipex
			make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re
