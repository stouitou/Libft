/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:04:44 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/10 12:40:51 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	found_new_line(char *stash)
{
	int	i;

	i = 0;
	while (stash && stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*stash_buffer(int fd, char *buffer, char *stash)
{
	char	*tmp;
	int		got;

	if (found_new_line(stash))
		return (stash);
	while (1)
	{
		got = read(fd, buffer, BUFFER_SIZE);
		if (got == -1)
			return (NULL);
		if (got == 0)
			break ;
		buffer[got] = '\0';
		tmp = ft_strjoin(stash, buffer);
		if (tmp == NULL)
			return (NULL);
		free(stash);
		stash = tmp;
		if (found_new_line(stash))
			break ;
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash && stash[i])
	{
		if (stash[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line = ft_strndup(stash, i);
	if (line == NULL)
		return (NULL);
	return (line);
}

static char	*clean_up(char **stash)
{
	char	*clean;
	int		i;

	i = 0;
	while (*stash && (*stash)[i])
	{
		if ((*stash)[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	clean = ft_strdup(*stash + i);
	free(*stash);
	*stash = clean;
	return (*stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[1025];
	char		*buffer;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		ft_free_str_array(stash);
		return (NULL);
	}
	stash[fd] = stash_buffer(fd, buffer, stash[fd]);
	free(buffer);
	if (stash[fd] == NULL)
	{
		ft_free_str_array(stash);
		return (NULL);
	}
	line = extract_line(stash[fd]);
	clean_up(&(stash[fd]));
	return (line);
}
