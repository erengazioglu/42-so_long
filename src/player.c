/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 00:42:29 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/05 01:32:37 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_game *game, e_key key)
{
	int	dir[2];

	get_move_dir(key, dir);
	dir[0] += game->player->pos[0];
	dir[1] += game->player->pos[1];
	ft_printf(
		"%sTile at (%d, %d): %c%s\n",
		CYN, dir[0], dir[1], get_map_tile(game, dir), RST
	);
	if (get_map_tile(game, dir) == '0')
	{
		render_cell(game, game->player->pos[0], game->player->pos[1]);
		game->player->pos[0] = dir[0];
		game->player->pos[1] = dir[1];
		render_obj(game, game->player, false);
	}
		// game->player->pos[0]
}