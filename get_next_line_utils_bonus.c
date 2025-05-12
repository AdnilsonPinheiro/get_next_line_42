/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:58:48 by adpinhei          #+#    #+#             */
/*   Updated: 2025/05/12 17:44:22 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_free_join(char *str1, char *str2)
{
	char	*dest;

	dest = ft_strjoin(str1, str2);
	if (!dest)
		return (free(str1), NULL);
	free(str1);
	return (dest);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!res)
		return (NULL);
	while (str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		res[i++] = str2[j++];
	res[i] = '\0';
	return (res);
}
