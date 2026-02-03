/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:48:40 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/03 14:11:42 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_file_frames(char *src);

// example: "assets/player1x3-00.xpm"
static char	*build_anim_fp(char *name, int frame)
{
	char	*fp;

	fp = ft_calloc(ft_strlen("assets/1x3-00.xpm") + ft_strlen(name) + 1, 1);
	if (!fp)
		return (NULL);
	ft_strcat(fp, "assets/");
	ft_strcat(fp, name);
	ft_strcat(fp, "1x3-");
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
	// int		i;
	
	game = (void *) game;
	anim = malloc(sizeof(anim));
	for (int i = 0; i < frames; i++)
	{
		fp = build_anim_fp(name, i);
		ft_printf("%sAnim filepath: %s%s\n", YEL, fp, RST);
		free(fp);
	}
	return (anim);
	// i = 0;
	
	// while (i < frames)
	// {
	// 	load_te
	// }
}