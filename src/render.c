/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:42:51 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/11 14:46:12 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_cell(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = x * GRID_SIZE * GRID_MULT;
	py = y * GRID_SIZE * GRID_MULT;
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(
			game->ctx, game->win, game->textures->wall, px, py);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(
			game->ctx, game->win, game->textures->empty, px, py);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(
			game->ctx, game->win, game->textures->exit, px, py);
}

void	render_row(t_game *game, int y)
{
	int	x;

	x = 0;
	while (x < game->map_size[0])
		render_cell(game, x++, y);
}

void	render_map(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_size[1])
		render_row(game, y++);
	game->last_update = current_time_ms();
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

	if (!game->dead)
		render_obj(game, game->player, true);
	obj = game->objs;
	while (obj)
	{
		render_obj(game, obj->content, true);
		obj = (t_list *) obj->next;
	}
}
