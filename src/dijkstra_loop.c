/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:46:35 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/11 14:37:21 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	discover(t_game *game, t_dijk *dijk, int x, int y)
{
	if (
		x < 0 || y < 0
		|| x >= game->map_size[0]
		|| y >= game->map_size[1]
	)
		return ;
	if (dijk->map[y][x] == '*')
		dijk->state = DIJK_FOUND_GOAL;
	else if (dijk->map[y][x] == ' ')
	{
		dijk->map[y][x] = '.';
		if (dijk->state != DIJK_FOUND_GOAL)
			dijk->state = DIJK_SPREAD;
	}
}

static void	spread(t_game *game, t_dijk *dijk, int x, int y)
{
	if (dijk->map[y][x] != '.')
		return ;
	discover(game, dijk, x, y + 1);
	discover(game, dijk, x, y - 1);
	discover(game, dijk, x + 1, y);
	discover(game, dijk, x - 1, y);
}

void	dijkstra_step(t_game *game, t_dijk *dijk)
{
	int		x;
	int		y;

	dijk->state = DIJK_NO_SPREAD;
	y = 0;
	while (y < game->map_size[1])
	{
		x = 0;
		while (x < game->map_size[0])
			spread(game, dijk, x++, y);
		y++;
	}
}
