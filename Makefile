CC		= cc
NAME	= so_long
BONUS	= so_long_bonus
CFLAGS	= -Wall -Werror -Wextra -g


# the following is for determining the OS for different MLX libraries

OS		= $(shell uname -s)
ifeq ($(OS),Linux)
# 	MLX		= minilibx-linux/mlx_linux
	LIBS	= -Llibft -lft -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm
endif
ifeq ($(OS),Darwin)
# 	MLX		= minilibx-linux/lmlx_Darwin
	LIBS	= -Llibft -lft -Lminilibx-linux -lmlx_Darwin -L/usr/X11/lib -lXext -lX11 -lm
endif

SRC		= \
		main.c \
		render.c \
		render_footer.c \
		init.c \
		console.c \
		objects.c \
		animations.c \
		time.c \
		util.c \
		player.c \
		move.c \
		cleanup.c \
		dijkstra_setup.c \
		dijkstra_loop.c
SRC_MANDATORY	= \
		parse_map.c \
		check.c
SRC_BONUS		= \
		parse_map_bonus.c \
		check_bonus.c

OBJ				:= $(SRC:%.c=obj/%.o)
OBJ_MANDATORY	:= $(SRC_MANDATORY:%.c=obj/%.o)
OBJ_BONUS		:= $(SRC_BONUS:%.c=obj/%.o)

all			: $(NAME) $(BONUS)

# # I wanted to include the MLX build inside my makefile,
# # but it relinks so I have no option but to leave it out.
#
# $(MLX):
# 	@make -C minilibx-linux

# $(NAME)		: $(OBJ) $(OBJ_MANDATORY) libft/libft.a $(MLX)
$(NAME)		: $(OBJ) $(OBJ_MANDATORY) libft/libft.a
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_MANDATORY) $(LIBS) -o $@
# $(BONUS)	: $(OBJ) $(OBJ_BONUS) libft/libft.a $(MLX)
$(BONUS)	: $(OBJ) $(OBJ_BONUS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_BONUS) $(LIBS) -o $@


$(OBJ): $(SRC:%.c=src/%.c) include/so_long.h
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $(@:obj/%.o=src/%.c) -o $@
$(OBJ_MANDATORY): $(SRC_MANDATORY:%.c=src/%.c) include/so_long.h
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $(@:obj/%.o=src/%.c) -o $@
$(OBJ_BONUS): $(SRC_BONUS:%.c=src/%.c) include/so_long.h
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $(@:obj/%.o=src/%.c) -o $@

libft/libft.a:
	make -C libft
clean	: 
	rm -rf obj
fclean	: clean
	rm -f $(NAME) $(BONUS)
	rm -f libft/libft.a
# 	make clean -C minilibx-linux
re: fclean all
