/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:05:00 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/11 13:47:01 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


char	*parse_row(t_game *game, char *row, int y)
{
	int	i;
	int	pos[2];

	if (!check_row(game, row, y))
		return (NULL);
	pos[0] = 0;
	pos[1] = y;
	i = 0;
	while (row[i])
	{
		if (ft_strchr("CP<>XWLK", row[i]))
		{
			if (!create_obj(game, row[i], pos))
				return (NULL);
			row[i] = '0';
		}
		else if (row[i] == 'E')
		{
			game->exit_pos[0] = pos[0];
			game->exit_pos[1] = pos[1];
		}
		pos[0] += 1;
		i++;
	}
	return (row);
}

bool	copy_map(char *fp, t_game *game)
{
	int		fd;
	int		y;
	char	*line;
	char	**map_ptr;

	game->map = malloc(game->map_size[1] * sizeof(char *));
	if (!game->map)
		return (game->error = MEM_MALLOC, false);
	fd = open(fp, O_RDONLY);
	if (fd == -1)
		return (game->error = MAP_INVALID_FILEPATH, false);
	map_ptr = game->map;
	line = get_next_line(fd);
	if (!line)
		return (game->error = MAP_READ_ERROR, false);
	y = 0;
	while (line)
	{
		*map_ptr = parse_row(game, line, y++);
		if (!(*map_ptr))
			return (free(line), false);
		map_ptr++;
		line = get_next_line(fd);
	}
	return (close(fd), true);
}

bool	parse_map(char *fp, t_game *game)
{
	if (!copy_map(fp, game))
		return (false);
	ft_printf(
		"%s%s | w: %d, h: %d%s\n", 
		YEL, fp, game->map_size[0], game->map_size[1], RST
	);
	return (true);
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