/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:57:58 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/11 15:08:00 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_patrol_dir(char type, int *dir)
{
	int	i;

	dir[0] = 0;
	dir[1] = 0;
	i = ft_strfind(">v<^", type);
	if (i % 2)
		dir[1] = 1 - (i > 1) * 2;
	else
		dir[0] = 1 - (i > 1) * 2;
}

void	get_move_dir(t_key key, int *dir)
{
	key -= 2;
	dir[0] = 0;
	dir[1] = 0;
	if (key % 2)
		dir[1] = 1 - (key > 1) * 2;
	else
		dir[0] = 1 - (key > 1) * 2;
}

char	get_tile(t_game *game, int x, int y)
{
	return (game->map[y][x]);
}

t_key	get_key_input(int keycode)
{
	if (keycode == 65307)
		return (KEY_QUIT);
	else if (keycode == 65363 || keycode == 100)
		return (KEY_E);
	else if (keycode == 65364 || keycode == 115)
		return (KEY_S);
	else if (keycode == 65361 || keycode == 97)
		return (KEY_W);
	else if (keycode == 65362 || keycode == 119)
		return (KEY_N);
	return (KEY_NONE);
}
