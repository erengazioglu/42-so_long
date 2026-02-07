/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:58:39 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/07 03:48:08 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	check_row(t_game *game, char *row, int y)
{
	int i;

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
		if (i > game->map_size[0] + 1)
			return (game->error = MAP_INVALID_ROW_LENGTH, false);
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

bool	get_map_dims(t_game *game, char *fp)
{
	int		fd;
	char	*line;

	fd = open(fp, O_RDONLY);
	if (fd == -1)
		return (game->error = MAP_INVALID_FILEPATH, false);
	line = get_next_line(fd);
	if (!line)
		return (game->error = MAP_READ_ERROR, false);
	game->map_size[0] = ft_strlen(line) - 1;
	game->map_size[1] = 0;
	while (line)
	{
		game->map_size[1]++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (true);
}

// bool	check_map(t_game *game, char *fp)
// {
// }