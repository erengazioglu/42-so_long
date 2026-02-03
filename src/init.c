/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 00:55:41 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/02 23:39:53 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game	*check_textures(t_game *game)
{
	if (
		game->textures->empty &&
		game->textures->wall &&
		game->textures->exit
	)
		return (game);
	return (NULL);
}

t_game	*init_textures(t_game *game)
{
	int	w;
	int h;

	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
		return (NULL);
	game->textures->empty = mlx_xpm_file_to_image(
		game->ctx, "assets/empty1x3.xpm", &w, &h
	);
	game->textures->wall = mlx_xpm_file_to_image(
		game->ctx, "assets/wall2x3-00.xpm", &w, &h
	);
	return (check_textures(game));
}

// void	*load_image_file(t_game *game, char *filepath, int *w, int *h)
// {
// 	void	*img;

// 	img = mlx_xpm_file_to_image(game->ctx, filepath, w, h);
// 	ft_lstadd_back(&(game->imglist), ft_lstnew(img));
// 	ft_printf("%Loaded image %p.%s Assets:\n", GRN, ft_lstlast(game->imglist), RST);
// 	ft_lstprint(game->imglist);
// 	return (img);
// }

t_game	*new_game(char *mapfile)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->objs = NULL;
	parse_map(mapfile, game);
	game->ctx = mlx_init();
	game->win = mlx_new_window(
		game->ctx,
		game->map_size[0] * GRID_SIZE * GRID_MULT,
		game->map_size[1] * GRID_SIZE * GRID_MULT,
		mapfile
	);
	init_textures(game);
	print_map(game);
	return (game);
}