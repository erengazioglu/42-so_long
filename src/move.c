/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:45:53 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/09 14:45:02 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_patrol(t_game *game, t_obj *obj, int *dir)
{
	char	tile;

	tile = get_tile(game, obj->pos[0] + dir[0], obj->pos[1] + dir[1]);
	if (tile == '0')
	{
		render_cell(game, obj->pos[0], obj->pos[1]);
		obj->pos[0] += dir[0];
		obj->pos[1] += dir[1];
		render_obj(game, obj, false);
	}
	if (game->player->pos[0] == obj->pos[0]
		&& game->player->pos[1] == obj->pos[1])
		end_game(game, false);

}

void	move_objects(t_game *game)
{
	t_list	*node;
	t_obj	*obj;
	int		dir[2];

	node = game->objs;
	while (node)
	{
		obj = node->content;
		if (ft_strchr(">v<^", obj->type))
		{
			get_patrol_dir(obj->type, dir);
			if (get_tile(game, obj->pos[0] + dir[0], obj->pos[1] + dir[1]) == '1')
			{
				obj->type = ">v<^"[(ft_strfind(">v<^", obj->type) + 2) % 4];
				dir[0] *= -1;
				dir[1] *= -1;
			}
			move_patrol(game, obj, dir);
		}
		node = node->next;
	}
}

void	move_player(t_game *game, int *dir)
{
	char	tile;

	tile = get_tile(game, dir[0], dir[1]);
	if (tile == '0')
	{
		render_cell(game, game->player->pos[0], game->player->pos[1]);
		game->player->pos[0] = dir[0];
		game->player->pos[1] = dir[1];
		render_obj(game, game->player, false);
		game->moves += 1;
	}
	else if (tile == 'E')
		end_game(game, true);
}