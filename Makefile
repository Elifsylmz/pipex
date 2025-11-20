NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c files.c func.c
OBJS = $(SRCS:.c=.o)

MYLIBFT = ./libft
LIBFT = $(MYLIBFT)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(MYLIBFT)

clean:
	rm -f $(OBJS)
	@make -C $(MYLIBFT) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(MYLIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
