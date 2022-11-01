/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 05:14:28 by psaeyang          #+#    #+#             */
/*   Updated: 2022/10/31 00:03:53 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
/*
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
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
