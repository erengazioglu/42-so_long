/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 00:55:41 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/05 10:49:17 by egaziogl         ###   ########.fr       */
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
	game->textures->exit = mlx_xpm_file_to_image(
		game->ctx, "assets/exit1x3.xpm", &w, &h
	);
	return (check_textures(game));
}

t_game	*init_animations(t_game *game)
{
	game->textures->player = create_anim(game, "player1", 8);
	game->textures->coin = create_anim(game, "coin1", 8);
	game->textures->slime = create_anim(game, "enemy1", 8);
	game->textures->bat = create_anim(game, "enemy2", 8);
	return (game);
}

t_game	*init_game(t_game *game)
{
	game->ctx = mlx_init();
	game->objs = NULL;
	game->moves = 0;
	game->score = 0;
	init_textures(game);
	init_animations(game);
	return (game);
}

t_game	*new_game(char *mapfile)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	init_game(game);
	parse_map(mapfile, game);
	print_map(game);
	game->win = mlx_new_window(
		game->ctx,
		game->map_size[0] * GRID_SIZE * GRID_MULT,
		game->map_size[1] * GRID_SIZE * GRID_MULT,
		mapfile
	);
	render_map(game);
	print_objs(game);
	return (game);
}
