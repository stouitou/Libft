/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:04:44 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/11 13:04:26 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	found_new_line(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*get_line(int fd, char *str, char *buffer)
{
	int		got;
	char	*tmp;

	if (str)
	{
		if (found_new_line(str))
			return (str);
	}
	got = 1;
	while (got)
	{
		got = read(fd, buffer, BUFFER_SIZE);
		if (got < 0)
			return (NULL);
		if (got == 0)
			break ;
		buffer[got] = '\0';
		tmp = ft_strjoin(str, buffer);
		free(str);
		str = tmp;
		if (found_new_line(buffer))
			break ;
	}
	return (str);
}

static char	*get_more(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	tmp = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (tmp == NULL)
	{
		free(str);
		exit (1);
	}
	if (tmp[0] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	str[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[1025];
	char		*buffer;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	line = get_line(fd, stash[fd], buffer);
	free(buffer);
	if (line == NULL)
		return (NULL);
	stash[fd] = get_more(line);
	return (line);
}
