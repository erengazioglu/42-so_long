/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:50:03 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/11 16:01:16 by egaziogl         ###   ########.fr       */
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
# define MLX_BLACK	0x00000000
# define MLX_RED	0x00DD6060
# define MLX_GREEN	0x0090DD80
# define MLX_BLUE	0x009080DD

# define GRID_SIZE	16
# ifndef GRID_MULT
#  define GRID_MULT	3
# endif
# define REFRESH_RATE 10
# define BTN_EXIT	17

typedef enum e_key
{
	KEY_NONE,
	KEY_QUIT,
	KEY_E,
	KEY_S,
	KEY_W,
	KEY_N
}	t_key;

typedef enum e_dijkstate
{
	DIJK_NO_SPREAD,
	DIJK_SPREAD,
	DIJK_FOUND_GOAL
}	t_dijkstate;

typedef enum e_err
{
	NO_ERROR,
	MAP_INVALID_FILEPATH,
	MAP_READ_ERROR,
	MAP_INVALID_TILE,
	MAP_INVALID_ROW_LENGTH,
	MAP_INVALID_BOUNDARY,
	MAP_INCOMPLETE,
	MAP_NO_VALID_PATH,
	MAP_NO_PLAYER,
	MAP_DUPLICATE,
	MAP_NL_ENDING,
	MAP_NO_COINS,
	MLX_INIT_ERROR,
	MLX_TEXTURE_ERROR,
	MEM_MALLOC
}	t_err;

typedef struct s_dijk
{
	char		**map;
	t_dijkstate	state;
}	t_dijk;

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
	t_anim	*player_weapon;
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
	bool		footer_text;
	int			map_size[2];
	int			exit_pos[2];
	int			last_update;
	int			moves;
	int			score;
	int			keys;
	int			coins;
	bool		weapon;
	bool		dead;
	char		**map;
	t_err		error;
	t_textures	*textures;
	t_obj		*player;
	t_list		*objs;
}	t_game;

bool	parse_map(t_game *game);
t_game	*new_game(char *map);
void	print_map(char **map, int map_size[2]);
void	print_objs(t_game *game);
void	print_error(t_game *game);
void	render_cell(t_game *game, int x, int y);
void	render_map(t_game *game);
void	render_obj(t_game *game, t_obj *obj, bool advance_frame);
void	render_objs(t_game *game);
void	render_text(t_game *game, char *str, int color);
bool	render_footer(t_game *game);
t_obj	*create_obj(t_game *game, char type, int pos[2]);
t_anim	*create_anim(t_game *game, char *name, int frames);
long	current_time_ms(void);
void	player_action(t_game *game, t_key key);
t_key	get_key_input(int keycode);
bool	get_map_dims(t_game *game, int fd);
void	get_move_dir(t_key key, int *dir);
void	get_patrol_dir(char type, int *dir);
t_obj	*get_obj(t_game *game, int pos[2]);
char	get_tile(t_game *game, int x, int y);
void	move_objects(t_game *game);
void	move_player(t_game *game, int *dir);
void	destroy_obj(t_game *game, t_obj *obj);
void	end_game(t_game *game, bool win);
void	crash(t_game *game);
void	cleanup(t_game *game);
bool	copy_map(t_game *game, char *fp);
bool	check_textures(t_game *game);
bool	check_row(t_game *game, int y);
bool	check_exit_reachable(t_game *game);
bool	check_args(int argc, char **argv);
t_dijk	*dijkstra_init(t_game *game);
void	dijkstra_step(t_game *game, t_dijk *dijk);
void	dijkstra_cleanup(t_game *game, t_dijk *dijk);
void	set_vector2(int *pos, int x, int y);

#endif
