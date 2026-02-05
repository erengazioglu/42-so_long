/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:57:58 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/05 01:26:34 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// 1 - (key - 3 > 0) * 2 -> 

// keys are ESWN = 2345
// so	(key % 2)		? vertical : horizontal
// and	(key / 2) - 1		? positive : negative
void	get_move_dir(e_key key, int *dir)
{
	dir[0] = 0;
	dir[1] = 0;
	if (key % 2)
		dir[1] = 1 - (key > 3) * 2;
	else
		dir[0] = 1 - (key > 3) * 2;
}

char	get_map_tile(t_game *game, int *pos)
{
	return (game->map[pos[1]][pos[0]]);
}

e_key	get_key_input(int keycode)
{
	if (keycode == 65307)
		return (QUIT);
	else if (keycode == 65363 || keycode == 100)
		return (E);
	else if (keycode == 65364 || keycode == 115)
		return (S);
	else if (keycode == 65361 || keycode == 97)
		return (W);
	else if (keycode == 65362 || keycode == 119)
		return (N);
	return (NOKEY);
}