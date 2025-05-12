/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:15:28 by adpinhei          #+#    #+#             */
/*   Updated: 2025/05/09 18:47:45 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*reads file into the buffer
updates the stash
checks for n read bytes*/
char	*ft_read_file(int fd, char *stash)
{
	char	*buffer;
	int		byte_read;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buffer), free(stash), NULL);
		buffer[byte_read] = '\0';
		stash = ft_free_join(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), stash);
}

/*copies the line to be returned from the stash*/
char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * ((stash[i] == '\n') + i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*updates the stash by line positions*/
char	*ft_update(char *stash)
{
	char	*upd;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	upd = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!upd)
		return (free(stash), NULL);
	i++;
	j = 0;
	while (stash[i])
		upd[j++] = stash[i++];
	upd[j] = '\0';
	return (free(stash), upd);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = ft_read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = ft_update(stash);
	return (line);
}
