CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./includes -I./libft

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap

SRCS =	src/main.c \
		src/parse_args.c \
		src/utils.c \
		src/operations.c \
		src/radix.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDE)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
