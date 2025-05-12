/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:58:27 by adpinhei          #+#    #+#             */
/*   Updated: 2025/05/12 16:30:28 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

/*gnl function*/
char	*get_next_line(int fd);

/*helper functions*/
char	*ft_read_file(char *stash, int fd);
char	*ft_line(char *stash);
char	*ft_update(char *stash);

/*utils*/
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_free_join(char *str1, char *str2);
char	*ft_strjoin(char *str1, char *str2);

#endif