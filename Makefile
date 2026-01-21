CC		= cc
NAME	= so_long
CFLAGS	= -Wall -Werror -Wextra -g
LIBS	= -Lminilibx-linux -lmlx_Linux -lXext -lX11
SRC		= \
		src/main.c

all		: test
test	: src/main.c
	$(CC) $(CFLAGS) $(SRC) $(LIBS) -o test.out