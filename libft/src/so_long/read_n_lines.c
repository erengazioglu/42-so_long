/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_n_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:54:50 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/10 11:23:41 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	cleanup(char **lines)
{
	char	**ptr;

	ptr = lines;
	while (*ptr)
		free(*(ptr++));
	free(lines);
}

char	**read_n_lines(char *fp, int n)
{
	int		fd;
	char	*line;
	char	**result;
	char	**result_cursor;

	fd = open(fp, O_RDONLY);
	if (fd == -1)
		return (NULL);
	result = malloc(n * sizeof(char *));
	if (!result)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (free(result), NULL);
	result_cursor = result;
	while (line && --n > 0)
	{
		line[ft_strlen(line) - 1] = '\0';
		*(result_cursor++) = line;
		line = get_next_line(fd);
	}
	if (n != 0)
		return (cleanup(result), NULL);
	if (line[ft_strlen(line) - 1 == '\n'])
	{
		ft_printf("last char of %s is a newline\n");
		line[ft_strlen(line) - 1] = '\0';
	}
	return (*result_cursor = line, result);
}
