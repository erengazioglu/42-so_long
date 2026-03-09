/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 00:42:29 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/09 15:02:13 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	end_game(t_game *game, bool win)
{
	game->dead = true;
	mlx_put_image_to_window(
		game->ctx, game->win,
		game->textures->empty,
		game->player->pos[0] * GRID_SIZE * GRID_MULT,
		game->player->pos[1] * GRID_SIZE * GRID_MULT
	);
	if (win)
		mlx_string_put(game->ctx, game->win,
			16 + GRID_MULT * GRID_SIZE * 3,
			(game->map_size[1]) * GRID_MULT * GRID_SIZE + 16,
			MLX_GREEN,
			"You win the game! Press any key to exit."
		);
	else
		mlx_string_put(game->ctx, game->win,
		16 + GRID_MULT * GRID_SIZE * 3,
			(game->map_size[1]) * GRID_MULT * GRID_SIZE + 16,
			MLX_RED,
			"A dead player is you! Press any key to exit."
		);
}

void	pick_up(t_game *game, t_obj *obj, int dir[2])
{
		if (obj->type == 'C')
			game->score += 5;
		else if (obj->type == 'W')
		{
			game->player->anim = game->textures->player_weapon;
			game->weapon = true;
		}
		else
			game->keys += 1;
		destroy_obj(game, obj);
		game->moves++;
		move_player(game, dir);
}

void	interact(t_game *game, t_obj *obj, int dir[2])
{
	if (ft_strchr("CWK", obj->type))
		pick_up(game, obj, dir);
	else if (obj->type == 'L' && game->keys)
	{
		destroy_obj(game, obj);
		game->keys -= 1;
	}
	else if (ft_strchr("X>v<^", obj->type))
	{
		if (game->weapon)
		{
			destroy_obj(game, obj);
			game->score += 1;
		}
		else
		{
			game->moves++;
			end_game(game, false);
		}
	}
	 
}

void	player_action(t_game *game, e_key key)
{
	int		dir[2];
	t_obj	*obj;

	get_move_dir(key, dir);
	dir[0] += game->player->pos[0];
	dir[1] += game->player->pos[1];
	obj = get_obj(game, dir);
	if (obj)
		interact(game, obj, dir);
	else
		move_player(game, dir);
	move_objects(game);
}
