/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_objs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:42:51 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/05 23:40:04 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_player(t_game *game, bool advance_frame)
{
	mlx_put_image_to_window(
		game->ctx, game->win,
		game->textures->empty,
		game->player->pos[0] * GRID_SIZE * GRID_MULT,
		game->player->pos[1] * GRID_SIZE * GRID_MULT
	);
	if (game->weapon)
		mlx_put_image_to_window(
			game->ctx, game->win,
			ft_lstget(game->textures->player_weapon->textures, game->player->frame),
			game->player->pos[0] * GRID_SIZE * GRID_MULT,
			game->player->pos[1] * GRID_SIZE * GRID_MULT
		);
	else
		mlx_put_image_to_window(
			game->ctx, game->win,
			ft_lstget(game->textures->player->textures, game->player->frame),
			game->player->pos[0] * GRID_SIZE * GRID_MULT,
			game->player->pos[1] * GRID_SIZE * GRID_MULT
		);
	if (advance_frame)
		game->player->frame = (game->player->frame + 1) 
			% game->player->anim->length;
}

void	render_obj(t_game *game, t_obj *obj, bool advance_frame)
{
	mlx_put_image_to_window(
		game->ctx, game->win,
		game->textures->empty,
		obj->pos[0] * GRID_SIZE * GRID_MULT,
		obj->pos[1] * GRID_SIZE * GRID_MULT
	);
	mlx_put_image_to_window(
		game->ctx, game->win,
		ft_lstget(obj->anim->textures, obj->frame),
		obj->pos[0] * GRID_SIZE * GRID_MULT,
		obj->pos[1] * GRID_SIZE * GRID_MULT
	);
	if (advance_frame)
		obj->frame = (obj->frame + 1) % obj->anim->length;
}

void	render_objs(t_game *game)
{
	t_list	*obj;
	
	render_player(game, true);
	obj = game->objs;
	while (obj)
	{
		render_obj(game, obj->content, true);
		obj = (t_list *) obj->next;
	}
}
