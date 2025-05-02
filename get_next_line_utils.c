/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:24:07 by adpinhei          #+#    #+#             */
/*   Updated: 2025/05/02 17:36:32 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*regular strjoin*/
char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strnlen(s1, '\0');
	len_s2 = ft_strnlen(s2, '\0');
	dest = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, len_s1 + 1);
	ft_strlcat(dest, s2, len_s2 + len_s1 + 1);
	return (dest);
}

/*strnjoin - strjoin but only until a char c*/
char	*ft_strnjoin(char *s1, char *s2, char chr)
{
	char	*dest;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strnlen(s1, chr);
	len_s2 = ft_strnlen(s2, '\0');
	dest = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, len_s1 + 1);
	ft_strlcat(dest, s2, len_s2 + len_s1 + 1);
	return (dest);
}

/*strldup - duplicates the src from a starting point*/
char	*ft_strldup(char *src, int i)
{
	char	*dest;
	int		size;
	int		j;

	j = 0;
	size = ft_strnlen(src, '\0') - ft_strnlen(src, '\n');
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
//	src = &src[ft_strnlen(src, '\n')];
	while (src)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while((i < size - 1) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return(ft_strlen(src));
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	s_dest;
	unsigned int	s_src;
	unsigned int	i;
	unsigned int	j;

	s_dest = (unsigned int)ft_strlen(dest);
	s_src = (unsigned int)ft_strlen(src);
	j = s_dest;
	i = 0;
	if (size <= s_dest || size == 0)
		return (size + s_src);
	while (size > (j + 1) && src[i] != '\0')
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (s_dest + s_src);
}
