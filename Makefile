CC		= cc
NAME	= so_long
CFLAGS	= -Wall -Werror -Wextra -g
LIBS	= -Llibft -lft -Lminilibx-linux -lmlx_Linux -lXext -lX11
SRC		= \
		src/main.c

all		: test
test	: src/main.c libft/libft.a
	$(CC) $(CFLAGS) $(SRC) $(LIBS) -o test.out
libft/libft.a:
	make -C libft