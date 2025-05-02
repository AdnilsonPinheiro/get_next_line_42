/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:10:39 by adpinhei          #+#    #+#             */
/*   Updated: 2025/05/02 17:44:49 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H



# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnjoin(char *s1, char *s2, char chr);
char	*ft_strldup(char *src, int i);
char	*get_next_line(int fd);

int	ft_strlen(char *str);
int	ft_strnlen(char *str, char chr);

size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlcat(char *dest, char *src, size_t size);


#endif