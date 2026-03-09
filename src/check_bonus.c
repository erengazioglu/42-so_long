/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:58:39 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/09 20:09:46 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	check_args(int argc , char **argv)
{
	char	*filename;

	if (argc != 2)
	{
		ft_printf("%sError:\nPlease specify exactly 1 map file as an argument.%s\n",
			RED, RST);
		return (false);
	}
	filename = ft_get_filename(argv[1]);
	if (!ft_str_endswith(filename, ".ber") || ft_strlen(filename) < 5)
	{
		ft_printf("%sError:\nMap file must be at least one character long, followed by a '.ber' extension.%s\n",
		RED, RST);
		return (false);
	}
	return (true);
}

bool	check_exit_reachable(t_game *game)
{
	int		*src;
	int		*dst;
	t_dijk	*dijk;

	src = game->player->pos;
	dst = game->exit_pos;
	ft_printf("finding valid path (%d, %d)->(%d, %d)\n",
		src[0], src[1], dst[0], dst[1]
	);
	dijk = dijkstra_init(game);
	print_map(dijk->map, game->map_size);
	if (!dijk)
		return (false);
	while (dijk->state == DIJK_SPREAD)
		dijkstra_step(game, dijk);
	if (dijk->state != DIJK_FOUND_GOAL)
	{
		game->error = MAP_NO_VALID_PATH;
		return (dijkstra_cleanup(dijk), false);
	}
	return (dijkstra_cleanup(dijk), true);
}


bool	check_row(t_game *game, char *row, int y)
{
	int i;

	if (
		ft_strlen(row) != 
		(size_t) game->map_size[0] + (y != game->map_size[1] - 1)
	)
		return (game->error = MAP_INVALID_ROW_LENGTH, false);
	if (row[0] != '1' || row[game->map_size[0] - 1] != '1')
		return (game->error = MAP_INVALID_BOUNDARY, false);
	if (y == 0 || y == game->map_size[1] - 1)
	{
		while (*row)
		{
			if (!ft_strchr("1\n", *(row++)))
				return (game->error = MAP_INVALID_BOUNDARY, false);
		}
		return (true);
	}
	i = 0;
	while (row[i])
	{
		if (!ft_strchr("10ECP<>XWLK\n", row[i++]))
			return (game->error = MAP_INVALID_TILE, false);
	}
	return (true);
}

bool	check_textures(t_game *game)
{
	if (
		game->textures->empty &&
		game->textures->wall &&
		game->textures->exit &&
		game->textures->player &&
		game->textures->player_weapon &&
		game->textures->coin &&
		game->textures->slime &&
		game->textures->bat &&
		game->textures->key &&
		game->textures->weapon &&
		game->textures->lock
	)
		return (true);
	return (game->error = MLX_TEXTURE_ERROR, false);
}
