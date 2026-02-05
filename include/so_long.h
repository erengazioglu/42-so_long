/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:50:03 by egaziogl          #+#    #+#             */
/*   Updated: 2026/02/05 18:08:37 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>
# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"

# define MLX_WHITE	0x00FFFFFF
# define GRID_SIZE	16
# ifndef GRID_MULT
#  define GRID_MULT	3
# endif

// key, button, notify
# define KEY_PRESS	2
# define BTN_EXIT	17
# define NOT_MAP	19

typedef enum
{
	NOKEY,
	QUIT,
	E, 		// 2
	S, 		// 3
	W, 		// 4
	N		// 5
}	e_key;

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
	t_anim	*slime;
	t_anim	*bat;
	t_anim	*key;
	t_anim	*weapon;
	t_anim	*lock;
}	t_textures;

typedef struct s_obj
{
	int		pos[2];
	int		frame;
	char	type;
	t_anim	*anim;
}	t_obj;

typedef struct s_game
{
	void		*ctx;
	void		*win;
	char		**map;
	int			map_size[2];
	int			last_update;
	int			moves;
	int			score;
	t_textures	*textures;
	t_obj		*player;
	t_obj		*exit;
	t_list		*objs;
}	t_game;

bool	parse_map(char *fp, t_game *game);
t_game	*new_game(char *map);
void	quit_game(t_game *game);
void	print_map(t_game *game);
void	print_objs(t_game *game);
void	render_cell(t_game *game, int x, int y);
void	render_map(t_game *game);
void	render_obj(t_game *game, t_obj *obj, bool advance_frame);
void	render_objs(t_game *game);
t_obj	*create_obj(t_game *game, char type, int pos[2]);
t_anim	*create_anim(t_game *game, char *name, int frames);
long	current_time_ms(void);
e_key	get_key_input(int keycode);
void	player_action(t_game *game, e_key key);
void	get_move_dir(e_key key, int *dir);
void	get_patrol_dir(char type, int *dir);
char	get_tile(t_game *game, int x, int y);
t_obj	*get_obj(t_game *game, int pos[2]);
void	destroy_obj(t_game *game, t_obj *obj);


#endif
