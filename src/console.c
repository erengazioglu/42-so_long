/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 00:40:24 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/31 01:48:59 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_size[1])
		ft_printf("%s", (game->map)[i++]);
	ft_printf("\n");
}