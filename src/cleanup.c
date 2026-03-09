/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:14:30 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/09 21:14:52 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_game *game)
{
	int	i;
	
	i = 0;
	while (i < game->map_size[1] && game->map[i])
		free(game->map[i++]);
	free(game->map);
}

void	free_objects(t_game *game)
{
	t_list	*node;
	t_list	*temp;

	if (game->player)
		free(game->player);
	node = game->objs;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp->content);
		free(temp);
	}
}

void	free_animation(t_game *game, t_anim *anim)
{
	t_list	*node;
	t_list	*temp;

	node = anim->textures;
	while (node)
	{
		temp = node;
		node = node->next;
		mlx_destroy_image(game->ctx, temp->content);
		free(temp);
	}
	free(anim);
}

void	free_textures(t_game *game)
{
	mlx_destroy_image(game->ctx, game->textures->empty);
	mlx_destroy_image(game->ctx, game->textures->wall);
	mlx_destroy_image(game->ctx, game->textures->exit);
	free_animation(game, game->textures->player);
	free_animation(game, game->textures->player_weapon);
	free_animation(game, game->textures->coin);
	free_animation(game, game->textures->slime);
	free_animation(game, game->textures->bat);
	free_animation(game, game->textures->key);
	free_animation(game, game->textures->weapon);
	free_animation(game, game->textures->lock);
}

void	free_mlx(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->ctx, game->win);
	free(game->ctx);
}

void	cleanup(t_game *game)
{
	if (!game)
		return ;
	if (game->textures)
		free_textures(game);
	free_objects(game);
	if (game->map)
		free_map(game);
	free_mlx(game);
}