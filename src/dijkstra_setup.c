/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:09:59 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/09 20:38:10 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	dijkstra_cleanup(t_game *game, t_dijk *dijk)
{
	int	i;
	
	i = 0;
	while (i < game->map_size[1])
		free(dijk->map[i++]);
	free(dijk->map);
	free(dijk);
}

static char	convert(char c)
{
	if (c == '1')
		return ('X');
	else if (c == 'E')
		return ('*');
	return (' ');
}

static bool	dijkstra_create_row(t_game *game, t_dijk *dijk, int y)
{
	int	x;

	dijk->map[y] = ft_calloc(game->map_size[0] + 1, 1);
	if (!dijk->map[y])
		return (game->error = MEM_MALLOC, false);
	x = 0;
	while (x < game->map_size[0])
	{
		if (game->player->pos[0] == x && game->player->pos[1] == y)
			dijk->map[y][x] = '.';
		else
			dijk->map[y][x] = convert(game->map[y][x]);
		x++;
	}
	return (true);
}

static bool	dijkstra_create_map(t_game *game, t_dijk *dijk)
{
	int		y;

	dijk->map = malloc(game->map_size[1] * sizeof(char *)); 
	if (!dijk->map)
		return (game->error = MEM_MALLOC, false);
	y = 0;
	while (y < game->map_size[1])
	{
		if (!dijkstra_create_row(game, dijk, y++))
			return (false);
	}
	return (true);
}

t_dijk	*dijkstra_init(t_game *game)
{
	t_dijk	*dijk;
	
	dijk = malloc(sizeof(t_dijk));
	if (!dijk)
		return (game->error = MEM_MALLOC, NULL);
	if (!dijkstra_create_map(game, dijk))
		return (game->error = MEM_MALLOC, dijkstra_cleanup(game, dijk), NULL);
	dijk->state = DIJK_SPREAD;
	return (dijk);
}
