/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:48:40 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/06 15:10:10 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*build_texture_fp(char *name)
{
	char	*fp;

	fp = ft_calloc(ft_strlen("assets/x3.xpm") + ft_strlen(name) + 1, 1);
	if (!fp)
		return (NULL);
	ft_strcat(fp, "assets/");
	ft_strcat(fp, name);
	ft_strcat(fp, "x3.xpm");
	return (fp);
}

static char	*build_anim_fp(char *name, int frame)
{
	char	*fp;

	fp = ft_calloc(ft_strlen("assets/x3-00.xpm") + ft_strlen(name) + 1, 1);
	if (!fp)
		return (NULL);
	ft_strcat(fp, "assets/");
	ft_strcat(fp, name);
	ft_strcat(fp, "x3-");
	if (frame < 10)
		ft_strcat(fp, "0");
	ft_strcat(fp, ft_itoa(frame));
	ft_strcat(fp, ".xpm");
	return (fp);
}

bool	add_texture_to_anim(t_game *game, t_anim *anim, char *fp, int *dims)
{
	void	*texture;
	t_list	*node;
	
	texture = mlx_xpm_file_to_image(game->ctx, fp, dims, dims + 1);
	if (!texture)
		return (game->error = MLX_TEXTURE_ERROR, false);
	node = ft_lstnew(texture);
	if (!node)
		return (game->error = MEM_MALLOC, false);
	ft_lstadd_back(&(anim->textures), node);
	return (true);
}

t_anim	*create_anim(t_game *game, char *name, int frames)
{
	t_anim	*anim;
	char	*fp;
	int		dims[2];
	int		i;

	anim = malloc(sizeof(t_anim));
	if (!anim)
		return (game->error = MEM_MALLOC, NULL);
	anim->length = frames;
	i = 0;
	while (i < frames)
	{
		if (frames == 1)
			fp = build_texture_fp(name);
		else
			fp = build_anim_fp(name, i);
		if (!fp)
			return (game->error = MEM_MALLOC, NULL);
		if (!add_texture_to_anim(game, anim, fp, dims))
			return (NULL);
		(free(fp), i = 0);
	}
	return (anim);
}
