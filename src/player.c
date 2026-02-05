/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 00:42:29 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/05 23:22:22 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_patrol(t_game *game, t_obj *obj, int *dir)
{
	char	tile;

	tile = get_tile(game, obj->pos[0] + dir[0], obj->pos[1] + dir[1]);
	ft_printf("%sbat: tile (%d, %d) is %c%s\n", 
		YEL, obj->pos[0] + dir[0], obj->pos[1] + dir[1], tile, RST);
	if (tile == '0')
	{
		render_cell(game, obj->pos[0], obj->pos[1]);
		obj->pos[0] += dir[0];
		obj->pos[1] += dir[1];
		render_obj(game, obj, false);
	}
	if (game->player->pos[0] == obj->pos[0]
		&& game->player->pos[1] == obj->pos[1])
	{
		ft_printf("%sA dead player is you!%s\n", RED, RST);
	}

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
			ft_printf("patrol found: %c\n", obj->type);
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
	{
		ft_printf("%sYou win the game!%s\n", GRN, RST);
		quit_game(game);
	}
}

void	interact(t_game *game, t_obj *obj, int dir[2])
{
	if (ft_strchr("CWK", obj->type))
	{
		destroy_obj(game, obj);
		move_player(game, dir);
		if (obj->type == 'C')
			game->score += 1;
		else if (obj->type == 'W')
			game->player->anim = game->textures->player_weapon;
		else
			game->keys += 1;
	}
	else if (obj->type == 'L' && game->keys)
	{
		destroy_obj(game, obj);
		game->keys -= 1;
	}
}

void	player_action(t_game *game, e_key key)
{
	int		dir[2];
	t_obj	*obj;

	get_move_dir(key, dir);
	dir[0] += game->player->pos[0];
	dir[1] += game->player->pos[1];
	ft_printf("Total moves: %d. ", game->moves);
	obj = get_obj(game, dir);
	if (obj)
	{
		ft_printf(
			"%sObj at (%d, %d): %c%s\n",
			CYN, dir[0], dir[1], get_obj(game, dir)->type, RST
		);
		interact(game, obj, dir);
	}
	else
	{
		ft_printf(
			"%sTile at (%d, %d): %c%s\n",
			CYN, dir[0], dir[1], get_tile(game, dir[0], dir[1]), RST
		);
		move_player(game, dir);
	}
	move_objects(game);
}
