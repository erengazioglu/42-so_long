/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:27:28 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/25 23:57:33 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*init_stash(char **stash)
{
	char	*new_stash;
	int		lb_pos;

	if (!(*stash))
	{
		*stash = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!(*stash))
			return (NULL);
		return (*stash);
	}
	lb_pos = ft_strfind(*stash, '\n');
	if (lb_pos == -1)
		return (free(*stash), *stash = NULL, NULL);
	new_stash = ft_strnjoin("", *stash + lb_pos + 1, -1, false);
	free(*stash);
	return (new_stash);
}

bool	init(int fd, char **stash, char **buffer, int *bytes_read)
{
	int	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (false);
	*stash = init_stash(stash);
	if (!(*stash))
		return (false);
	*buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!(*buffer))
		return (free(*stash), stash = NULL, false);
	ft_strcpy_lb(*buffer, *stash, '\0', false);
	*bytes_read = BUFFER_SIZE;
	i = 0;
	while ((*stash)[i])
		(*stash)[i++] = '\0';
	return (true);
}

char	*handle_lb(char **stash, char *buffer, int lb_pos, int bytes_read)
{
	char	*result;
	int		stash_len;

	stash_len = ft_strlen(*stash);
	*stash = ft_strnjoin(*stash, buffer, bytes_read, true);
	if (!(*stash))
		return (free(buffer), NULL);
	result = ft_strnjoin("", *stash, stash_len + lb_pos + 1, false);
	if (!result)
		return (free(*stash), free(buffer), (*stash) = NULL, NULL);
	return (free(buffer), result);
}

char	*handle_eof(char **stash, char *buffer, int bytes_read)
{
	char	*result;

	result = NULL;
	if (bytes_read == 0)
	{
		if (ft_strlen(*stash) != 0)
			result = ft_strnjoin("", *stash, -1, false);
		return (free(buffer), free(*stash), *stash = NULL, result);
	}
	*stash = ft_strnjoin(*stash, buffer, bytes_read, true);
	free(buffer);
	if (!(*stash))
		return (NULL);
	result = ft_strnjoin("", *stash, -1, false);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	int			bytes_read;
	int			lb_pos;

	if (!init(fd, &stash, &buffer, &bytes_read))
		return (stash = NULL, NULL);
	if (!(*buffer))
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (free(stash), free(buffer), stash = NULL, NULL);
	lb_pos = ft_strfind(buffer, '\n');
	while (bytes_read == BUFFER_SIZE && lb_pos == -1)
	{
		stash = ft_strnjoin(stash, buffer, -1, true);
		if (!stash)
			return (free(buffer), NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(stash), free(buffer), stash = NULL, NULL);
		lb_pos = ft_strfind(buffer, '\n');
	}
	if (lb_pos != -1)
		return (handle_lb(&stash, buffer, lb_pos, bytes_read));
	return (handle_eof(&stash, buffer, bytes_read));
}
