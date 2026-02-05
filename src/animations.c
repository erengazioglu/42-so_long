/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:48:40 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/05 17:40:45 by egaziogl         ###   ########.fr       */
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

t_anim	*create_anim(t_game *game, char *name, int frames)
{
	t_anim	*anim;
	char	*fp;
	int		w;
	int		h;
	// int		i;
	
	w = 0;
	h = 0;
	anim = malloc(sizeof(t_anim));
	anim->length = frames;
	for (int i = 0; i < frames; i++)
	{
		if (frames == 1)
			fp = build_texture_fp(name);
		else
			fp = build_anim_fp(name, i);
		ft_printf("%sAnim filepath: %s%s\n", YEL, fp, RST);
		ft_lstadd_back(&(anim->textures), ft_lstnew(mlx_xpm_file_to_image(game->ctx, fp, &w, &h)));
		free(fp);
	}
	return (anim);
}
