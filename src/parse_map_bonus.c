/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:05:00 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/11 12:22:56 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	copy_map(t_game *game, char *fp)
{
	game->map = read_n_lines(fp, game->map_size[1]);
	if (!game->map)
		return (game->error = MAP_READ_ERROR, false);
	return (true);
}

static bool	parse_row(t_game *game, int y)
{
	char	*row;
	int		pos[2];

	row = game->map[y];
	(pos[0] = 0, pos[1] = y);
	while (pos[0] < game->map_size[0])
	{
		if (ft_strchr("CP<>XWLK", row[pos[0]]))
		{
			if (!create_obj(game, row[pos[0]], pos))
				return (false);
			row[pos[0]] = '0';
		}
		else if (row[pos[0]] == 'E')
			(game->exit_pos[0] = pos[0], game->exit_pos[1] = pos[1]);
		pos[0]++;
	}
	return (true);
}

bool	parse_map(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_size[1])
	{
		if (
			!check_row(game, y)
			|| !parse_row(game, y)
		)
			return (false);
		y++;
	}
	if (!game->player)
		return (game->error = MAP_NO_PLAYER, false);
	return (true);
}

bool	get_map_dims(t_game *game, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (game->error = MAP_READ_ERROR, false);
	game->map_size[0] = ft_strlen(line) - 1;
	game->map_size[1] = 0;
	while (line && *line != '\n')
	{
		game->map_size[1]++;
		(free(line), line = get_next_line(fd));
	}
	if (line && *line == '\n')
	{
		(free(line), line = get_next_line(fd));
		if (line)
		{
			while (line)
				(free(line), line = get_next_line(fd));
			return (free(line), game->error = MAP_NL_ENDING, false);
		}
	}
	return (close(fd), true);
}
