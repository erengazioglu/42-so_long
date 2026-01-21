/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:42:11 by egaziogl          #+#    #+#             */
/*   Updated: 2026/01/15 14:40:31 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	free_list(char **list)
{
	while (*list)
		free(*(list++));
	free(list);
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	pick_word(char const *s, char c, char **result)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	*result = ft_substr(s, 0, len);
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	**retval;

	result = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	retval = result;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			s += pick_word(s, c, result);
			if (!(*result))
			{
				free_list(retval);
				return (NULL);
			}
			result++;
		}
	}
	return (retval);
}
