/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:50:53 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/27 19:05:44 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

void	cleanup_images(t_game *game)
{
	while (game->imglist)
	{
		// ft_printf("freeing image %p\n", game->imglist->content);
		mlx_destroy_image(game->ctx, game->imglist->content);
		if (game->imglist->next)
		{
			game->imglist = game->imglist->next;
			free(game->imglist->prev);
			game->imglist->prev = NULL;
		}
		else
		{
			free(game->imglist);
			game->imglist = NULL;
		}
	}
}

void	quit_game(t_game *game)
{
	// mlx_clear_window(game->ctx, game->win);
	cleanup_images(game);
	mlx_destroy_window(game->ctx, game->win);
	free(game->ctx);
	free(game);
	exit(0);
}

int	handle_keypress(int keycode, void *params)
{
	t_game	*game;
	
	game = (t_game *) params;
	if (keycode == 65307)
		quit_game(game);
	else
		ft_printf("Key pressed: %d\n", keycode);
	return (0);
}

void	*load_image_file(t_game *game, char *filepath, int *w, int *h)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->ctx, filepath, w, h);
	ft_lstadd_back(&(game->imglist), ft_lstnew(img));
	// ft_printf("%Loaded image %p.%s Assets:\n", GRN, ft_lstlast(game->imglist), RST);
	// ft_lstprint(game->imglist);
	return (img);
}

// t_game	*new_game(char *title, int w, int h)
t_game	*new_game(char *map)
{
	t_game	*game;
	int		dims[2];
	(void) map;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->ctx = mlx_init();
	game->win = mlx_new_window(
		game->ctx,
		10 * GRID_SIZE * GRID_MULT,
		10 * GRID_SIZE * GRID_MULT,
		"So Long!"
	);
	game->imglist = NULL;
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	void	*wall;
	void	*empty;
	void	*exit;
	int		w;
	int		h;

	if (argc == 1)
	{
		ft_printf("%sYou need to specify at least 1 map file.%s\n", RED, RST);
		return (1);
	}

	game = new_game(argv[1]);
	wall = load_image_file(game, "assets/wall-01_x3.xpm", &w, &h);
	empty = load_image_file(game, "assets/empty-01_x3.xpm", &w, &h);
	exit = load_image_file(game, "assets/exit-01-x3.xpm", &w, &h);
	// ft_printf("%sloaded images %p, %p, %p%s\n", GRN, wall, empty, exit, RST);
	for (int x = 0; x < 10; x++)
	{
		mlx_put_image_to_window(game->ctx, game->win, wall, w * x, 0);
		mlx_put_image_to_window(game->ctx, game->win, wall, w * x, w * 9);
	}
	for (int y = 1; y < 9; y++)
	{
		mlx_put_image_to_window(game->ctx, game->win, wall, 0, w * y);
		mlx_put_image_to_window(game->ctx, game->win, wall, w * 9, w * y);
	}
	for (int x = 1; x < 9; x++)
	{
		for (int y = 1; y < 9; y++)
		mlx_put_image_to_window(game->ctx, game->win, empty, w * x, w * y);
	}
	mlx_put_image_to_window(game->ctx, game->win, exit, w * 8, w);
	
	mlx_key_hook(game->win, &handle_keypress, game);
	return (mlx_loop(game->ctx));
}