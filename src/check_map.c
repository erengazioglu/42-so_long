/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:58:39 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/06 14:55:11 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	get_map_dims(char *fp, t_game *game)
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
		if (!line)
			return (game->error = MAP_READ_ERROR, false);
	}
	close(fd);
	return (true);
}

// bool	check_map(t_game *game, char *fp)
// {
// }