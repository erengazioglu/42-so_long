/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:05:00 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/11 00:36:16 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


// 	game->map = 
// }

// static char	*parse_row(t_game *game, char *row, int y)
// {
// 	int	i;
// 	int	pos[2];

// 	if (!check_row(game, row, y))
// 		return (NULL);
// 	pos[0] = 0;
// 	pos[1] = y;
// 	i = 0;
// 	while (row[i])
// 	{
// 		if (ft_strchr("CP", row[i]))
// 		{
// 			if (!create_obj(game, row[i], pos))
// 				return (NULL);
// 			row[i] = '0';
// 		}
// 		else if (row[i] == 'E')
// 		{
// 			game->exit_pos[0] = pos[0];
// 			game->exit_pos[1] = pos[1];
// 		}
// 		pos[0] += 1;
// 		i++;
// 	}
// 	return (row);
// }

// static bool	copy_map(char *fp, t_game *game)
// {
// 	int		fd;
// 	int		y;
// 	char	*line;
// 	char	**map_ptr;

// 	game->map = malloc(game->map_size[1] * sizeof(char *));
// 	if (!game->map)
// 		return (game->error = MEM_MALLOC, false);
// 	fd = open(fp, O_RDONLY);
// 	if (fd == -1)
// 		return (game->error = MAP_INVALID_FILEPATH, false);
// 	map_ptr = game->map;
// 	line = get_next_line(fd);
// 	if (!line)
// 		return (game->error = MAP_READ_ERROR, false);
// 	y = 0;
// 	while (line)
// 	{
// 		*map_ptr = parse_row(game, line, y++);
// 		if (!(*map_ptr))
// 			return (free(line), false);
// 		map_ptr++;
// 		line = get_next_line(fd);
// 	}
// 	return (close(fd), true);
// }

static bool	parse_row(t_game *game, int y)
{
	char	*row;
	int		pos[2];

	row = game->map[y];
	(pos[0] = 0, pos[1] = y);
	ft_printf("parsing...\n");
	while (pos[0] < game->map_size[0])
	{
		if (ft_strchr("CP", row[pos[0]]))
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

// int	main(int argc, char **argv)
// {
// 	t_game	*game;

// 	ft_printf("RUNNING %s\n", argv[1]);
// 	if (argc != 2)
// 		return (1);
// 	game = malloc(sizeof(t_game));
// 	init_game(game, argv[1]);
// 	ft_printf("map size: (%d, %d)\n", game->map_size[0], game->map_size[1]);
// 	if (game->map_size[1])
// 	game->map = read_n_lines(argv[1], game->map_size[1]);
// 	if (!parse_map(game))
// 		print_error(game);
// 	else
// 	{
// 		ft_printf("%s", GRN);
// 		for (int i = 0; i < game->map_size[1]; i++)
// 			ft_printf("%s\n", game->map[i]);
// 		ft_printf("%s", RST);
// 	}
// 	// if (game->error)
// 	// 	print_error(game);
// }
