/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:56:29 by psaeyang          #+#    #+#             */
/*   Updated: 2022/11/01 19:57:02 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
/*
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
*/
char	*get_next_line(int fd);
char	*get_this_line(char *keep);
char	*keep_this_line(char *keep, int rslen);
char	*ft_strjoin(char *s1, char *s2);
char	*readfile(int fd, char *keep);
size_t	ft_strlen_n(const char *s, char c);
int		ft_find_n(char *s);

#endif
