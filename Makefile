CC		= cc
NAME	= so_long
CFLAGS	= -Wall -Werror -Wextra -g

# os-specific instructions
OS		= $(shell uname -s)
ifeq ($(OS),Linux)
    LIBS = -Llibft -lft -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm
endif
ifeq ($(OS),Darwin)
    LIBS = -Llibft -lft -Lminilibx-linux -lmlx_Darwin -L/usr/X11/lib -lXext -lX11 -lm
endif

SRC		= \
		src/main.c \
		src/parse_map.c \
		src/render_map.c \
		src/render_objs.c \
		src/init.c \
		src/console.c \
		src/objects.c \
		src/animations.c \
		src/time.c \
		src/util.c \
		src/player.c \
		src/move.c

all		: test
test	: src/main.c libft/libft.a
	$(CC) $(CFLAGS) $(SRC) $(LIBS) -o test.out
libft/libft.a:
	make -C libft