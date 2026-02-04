/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_objs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:42:51 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/04 22:51:18 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_obj(t_game *game, t_obj *obj)
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
	obj->frame = (obj->frame + 1) % obj->anim->length;
}

void	render_objs(t_game *game)
{
	t_list	*obj;
	
	render_obj(game, game->player);
	obj = game->objs;
	while (obj)
	{
		render_obj(game, obj->content);
		obj = (t_list *) obj->next;
	}
}
