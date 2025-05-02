/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:15:28 by adpinhei          #+#    #+#             */
/*   Updated: 2025/05/02 18:11:16 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*measures the size of a string up until a char c*/
int	ft_strnlen(char *str, char chr)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != chr)
		i++;
	return (++i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str);
	while (i <= size)
	{
		if ((char)str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buf[BUFFER_SIZE];
	char		*line;
	char		*save;

	line = NULL;
	save = NULL;
	stash = ft_strjoin(stash, buf);
	read(fd, buf, BUFFER_SIZE);
	if (BUFFER_SIZE == 0)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
		get_next_line(fd);
	line = ft_strnjoin(stash, line, '\n');/*substr(stash, 0, ate strchr(\n))*/
	save = ft_strldup(stash, ft_strnlen(line, '\0'));
	free(stash);
	stash = save;
	free(save);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
}
