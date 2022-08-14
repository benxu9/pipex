NAME = pipex

SRCS = main.c \
		parse_env.c \
		openfile.c \

CC = gcc

LIBFT=libft/libft.a

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		$(MAKE) -C ./libft

clean:
		$(MAKE) clean -C ./libft
		rm -f $(OBJS)

fclean: clean
		$(MAKE) clean -C ./libft
		rm -f $(NAME)

re: fclean all 