/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 00:55:41 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/02 06:32:05 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	init_window(t_game *game)
{
	game->win = mlx_new_window(
		game->ctx,
		game->map_size[0] * GRID_SIZE * GRID_MULT,
		game->map_size[1] * GRID_SIZE * GRID_MULT,
		"So long!"
	);
	if (!game->win)
		return (game->error = MLX_INIT_ERROR, false);
	render_map(game);
	return (true);
}

bool	init_textures(t_game *game)
{
	int	w;
	int h;

	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
		return (game->error = MEM_MALLOC, false);
	game->textures->empty = mlx_xpm_file_to_image(
		game->ctx, "assets/textures/empty1x3.xpm", &w, &h
	);
	game->textures->wall = mlx_xpm_file_to_image(
		game->ctx, "assets/textures/wall2x3-00.xpm", &w, &h
	);
	game->textures->exit = mlx_xpm_file_to_image(
		game->ctx, "assets/textures/exit1x3.xpm", &w, &h
	);
	return (true);
}

bool	init_animations(t_game *game)
{
	game->textures->player = create_anim(game, "player1", 8);
	game->textures->player_weapon = create_anim(game, "player2", 8);
	game->textures->coin = create_anim(game, "coin1", 8);
	game->textures->slime = create_anim(game, "enemy1", 8);
	game->textures->bat = create_anim(game, "enemy2", 8);
	game->textures->weapon = create_anim(game, "weapon1", 1);
	game->textures->key = create_anim(game, "key1", 1);
	game->textures->lock = create_anim(game, "door2", 1);
	return (true);
}

bool	init_game(t_game *game, char *mapfile)
{
	game->error = NO_ERROR;
	game->objs = NULL;
	game->player = NULL;
	game->map = NULL;
	game->textures = NULL;
	game->ctx = mlx_init();
	if (!game->ctx)
		return (game->error = MLX_INIT_ERROR, false);
	game->moves = 0;
	game->score = 0;
	game->keys = 0;
	game->weapon = false;
	game->dead = false;
	return (get_map_dims(game, mapfile));
}

t_game	*new_game(char *mapfile)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	if (
		!init_game(game, mapfile)
		|| !init_textures(game) 
		|| !init_animations(game)
		|| !check_textures(game)
		|| !parse_map(mapfile, game)
		|| !check_player_exists(game)
		|| !check_exit_reachable(game)
		|| !init_window(game)
	)
		crash(game);
	print_objs(game);
	return (game);
}
