/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:05:00 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/05 17:27:54 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	get_map_dims(char *fp, t_game *game)
{
	int		fd;
	char	*line;

	ft_printf("map name: %s\n", fp);
	fd = open(fp, O_RDONLY);
	ft_printf("fd = %d\n", fd);
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("%sCouldn't read file.%s\n", RED, RST);
		game->map_size[0] = -1;
		game->map_size[1] = -1;
		return (false);
	}
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

char	*parse_row(char *row, t_game *game, int y)
{
	char	*ptr;
	int		pos[2];

	ptr = row;
	pos[0] = 0;
	pos[1] = y;
	while (*ptr)
	{
		if (ft_strchr("CP<>XW", *ptr))
		{
			create_obj(game, *ptr, pos);
			*ptr = '0';
		}
		pos[0] += 1;
		ptr++;
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
	return (true);
}

bool	parse_map(char *fp, t_game *game)
{
	get_map_dims(fp, game);
	if (game->map_size[0] == -1)
		return (false);
	copy_map(fp, game);
	ft_printf(
		"%s%s | w: %d, h: %d%s\n", 
		YEL, fp, game->map_size[0], game->map_size[1], RST
	);
	return (false);
}