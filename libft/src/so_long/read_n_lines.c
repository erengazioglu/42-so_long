/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_n_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:54:50 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/11 15:34:17 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	fast_forward(char *line, int fd)
{
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
}

static void	cleanup(char **lines)
{
	char	**ptr;

	ptr = lines;
	while (*ptr)
		free(*(ptr++));
	free(lines);
}

static char	*init(char *fp, int n, int *fd, char ***result)
{
	char	*line;

	*fd = open(fp, O_RDONLY);
	if (*fd == -1)
		return (NULL);
	*result = malloc(n * sizeof(char *));
	if (!(*result))
		return (close(*fd), NULL);
	line = get_next_line(*fd);
	if (!line)
		return (free(result), close(*fd), NULL);
	return (line);
}

char	**read_n_lines(char *fp, int n)
{
	int		fd;
	char	*line;
	char	**result;
	char	**result_cursor;

	line = init(fp, n, &fd, &result);
	result_cursor = result;
	while (line && --n > 0)
	{
		if (line[ft_strlen(line) - 1 == '\n'])
			line[ft_strlen(line) - 1] = '\0';
		*(result_cursor++) = line;
		line = get_next_line(fd);
	}
	if (n != 0)
		return (cleanup(result), close(fd), NULL);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	*result_cursor = line;
	return (fast_forward(line, fd), result);
}
