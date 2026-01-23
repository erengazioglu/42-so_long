/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:50:03 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/23 14:31:01 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../libft/include/libft.h"

# define MLX_WHITE	0x00FFFFFF
# define GRID_SIZE	16
# ifndef GRID_MULT
#  define GRID_MULT	3
# endif

typedef struct s_game
{
	void	*ctx;
	void	*win;
	t_list	*imglist;
}	t_game;

#endif
