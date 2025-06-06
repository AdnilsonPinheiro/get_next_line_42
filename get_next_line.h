/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:10:39 by adpinhei          #+#    #+#             */
/*   Updated: 2025/05/09 19:51:44 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);

/*utils*/
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_free_join(char *stash, char *buffer);
char	*ft_strjoin(char *s1, char *s2);

/*helpers*/
char	*ft_read_file(int fd, char *res);
char	*ft_line(char *stash);
char	*ft_update(char *stash);

#endif
