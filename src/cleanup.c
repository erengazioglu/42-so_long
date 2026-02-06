/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:14:30 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/06 17:35:56 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_objects(t_game *game)
{
	t_list	*node;
	t_list	*temp;

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

void	free_animation(t_anim *anim)
{
	t_list	*node;
	t_list	*temp;

	node = anim->textures;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp->content);
		free(temp);
	}
	free(anim);
}

void	free_textures(t_game *game)
{
	free(game->textures->empty);
	free(game->textures->wall);
	free(game->textures->exit);
	free_animation(game->textures->player);
	free_animation(game->textures->player);
	free_animation(game->textures->player);
	free_animation(game->textures->player);
	free_animation(game->textures->player);
	free_animation(game->textures->player);
	free_animation(game->textures->player);
	free_animation(game->textures->player);
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
	free_mlx(game);
	if (game->textures)
		free_textures(game);
	free_objects(game);
}