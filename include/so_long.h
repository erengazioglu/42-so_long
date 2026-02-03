/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:50:03 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/03 14:08:57 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"

# define MLX_WHITE	0x00FFFFFF
# define GRID_SIZE	16
# ifndef GRID_MULT
#  define GRID_MULT	3
# endif

// typedef enum
// {
// 	PLAYER,
// 	COIN,
// 	WEAPON,
// 	GUARD,
// 	PATROL_E,
// 	PATROL_S,
// 	PATROL_W,
// 	PATROL_N
// }	e_type;

typedef struct s_anim
{
	int		length;
	t_list	*textures;
}	t_anim;

typedef struct s_textures
{
	void	*empty;
	void	*wall;
	void	*exit;
	t_anim	*player;
	t_anim	*coin;
	t_anim	*bat;
	t_anim	*slime;
}	t_textures;

typedef struct s_obj
{
	int		pos[2];
	int		frame;
	char	type;
}	t_obj;

typedef struct s_game
{
	void		*ctx;
	void		*win;
	char		**map;
	int			map_size[2];
	t_textures	*textures;
	t_obj		*player;
	t_obj		*exit;
	t_list		*objs;
}	t_game;

bool	parse_map(char *fp, t_game *game);
t_game	*new_game(char *map);
void	print_map(t_game *game);
void	print_objs(t_game *game);
void	draw_map(t_game *game);
t_obj	*create_obj(t_game *game, char type, int pos[2]);
t_anim	*create_anim(t_game *game, char *name, int frames);


#endif
