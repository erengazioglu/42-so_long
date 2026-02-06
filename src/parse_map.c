/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:05:00 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/06 16:48:45 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


char	*parse_row(char *row, t_game *game, int y)
{
	int	i;
	int	pos[2];

	pos[0] = 0;
	pos[1] = y;
	i = 0;
	while (row[i])
	{
		if (!ft_strchr("10ECP<>XWLK\n", row[i]))
		{
			free(row);
			return (NULL);
		}
		if (ft_strchr("CP<>XWLK", row[i]))
		{
			create_obj(game, row[i], pos);
			row[i] = '0';
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
		return (false);
	fd = open(fp, O_RDONLY);
	map_ptr = game->map;
	line = get_next_line(fd);
	if (!line)
		return (false);
	y = 0;
	while (line)
	{
		*map_ptr = parse_row(line, game, y++);
		map_ptr++;
		line = get_next_line(fd);
	}
	close(fd);
	return (true);
}

bool	parse_map(char *fp, t_game *game)
{
	if (game->map_size[0] == -1)
		return (false);
	copy_map(fp, game);
	ft_printf(
		"%s%s | w: %d, h: %d%s\n", 
		YEL, fp, game->map_size[0], game->map_size[1], RST
	);
	return (true);
}