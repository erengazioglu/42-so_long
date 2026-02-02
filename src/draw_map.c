/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:58:19 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/02 15:50:41 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map_cell(t_game *game, int x, int y)
{
	int	px;
	int py;

	px = x * GRID_SIZE * GRID_MULT;
	py = y * GRID_SIZE * GRID_MULT;
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(
			game->ctx, game->win, game->textures->wall, px, py);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(
			game->ctx, game->win, game->textures->exit, px, py);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(
			game->ctx, game->win, game->textures->empty, px, py);
}

void	draw_row(t_game *game, int y)
{
	int	x;

	x = 0;
	while (x < game->map_size[0])
		draw_map_cell(game, x++, y);
}

void	draw_map(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_size[1])
		draw_row(game, y++);
}