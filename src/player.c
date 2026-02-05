/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 00:42:29 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/05 02:24:09 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	interact(t_game *game, t_obj *obj)
{
	if (obj->type == 'C')
	{
		game->score += 1;
		destroy_obj(game, obj);
	}
}

void	move_player(t_game *game, e_key key)
{
	int		dir[2];
	t_obj	*obj;

	get_move_dir(key, dir);
	dir[0] += game->player->pos[0];
	dir[1] += game->player->pos[1];
	obj = get_obj(game, dir);
	if (obj)
		interact(game, obj);
	else if (get_map_tile(game, dir) == '0')
	{
		render_cell(game, game->player->pos[0], game->player->pos[1]);
		game->player->pos[0] = dir[0];
		game->player->pos[1] = dir[1];
		render_obj(game, game->player, false);
		game->moves += 1;
	}
	ft_printf(
		"Total moves: %d. %sTile at (%d, %d): %c%s\n",
		game->moves, CYN, dir[0], dir[1], get_map_tile(game, dir), RST
	);
		// game->player->pos[0]
}