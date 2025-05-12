/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:56:35 by adpinhei          #+#    #+#             */
/*   Updated: 2025/05/12 17:56:37 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = malloc(sizeof(char) * 1);
		if (!stash[fd])
			return (NULL);
		stash[fd][0] = '\0';
	}
	stash[fd] = ft_read_file(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	line = ft_line(stash[fd]);
	if (!line)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = ft_update(stash[fd]);
	return (line);
}

char	*ft_read_file(char *stash, int fd)
{
	char	*buf;
	int		byte_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(stash), NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buf), free(stash), NULL);
		buf[byte_read] = '\0';
		stash = ft_free_join(stash, buf);
		if (!stash)
			return (free(buf), NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (stash);
}

char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1 + (stash[i] == '\n')));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update(char *stash)
{
	char	*upd;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	upd = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!upd)
	{
		free(stash);
		return (NULL);
	}
	i++;
	j = 0;
	while (stash[i])
		upd[j++] = stash[i++];
	upd[j] = '\0';
	free(stash);
	return (upd);
}
