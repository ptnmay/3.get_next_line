/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:56:13 by psaeyang          #+#    #+#             */
/*   Updated: 2022/11/01 20:02:19 by psaeyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*keep_this_line(char *keep, int rslen)
{
	char	*tmp;

	if (!keep[rslen] || keep[rslen + 1] == '\0')
	{
		free (keep);
		return (NULL);
	}	
	tmp = malloc(1);
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	if (keep[rslen] == '\n')
		rslen++;
	tmp = ft_strjoin(tmp, &keep[rslen]);
	free (keep);
	return (tmp);
}

char	*get_this_line(char *keep)
{
	char	*kept;
	int		i;

	i = 0;
	if (!keep[0])
		return (NULL);
	kept = malloc(sizeof(char) + (ft_strlen_n(keep, '\n') + 1));
	if (!kept)
		return (NULL);
	while (keep[i] != '\n' && keep[i] != '\0')
	{
		kept[i] = keep[i];
		i++;
	}
	if (keep[i] == '\n')
	{
		kept[i] = keep[i];
		i++;
	}
	kept[i] = '\0';
	return (kept);
}

char	*readfile(int fd, char *keep)
{
	char	*buf;
	int		nb;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	nb = 1;
	while (nb > 0)
	{
		nb = read(fd, buf, BUFFER_SIZE);
		if (nb < 0)
		{
			free (buf);
			return (NULL);
		}
		buf[nb] = '\0';
		keep = ft_strjoin(keep, buf);
		if (ft_find_n(buf))
			break ;
	}
	free (buf);
	return (keep);
}

char	*get_next_line(int fd)
{
	static char	*keep[OPEN_MAX];
	char		*rsline;
	size_t		rslen;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!keep[fd])
	{
		keep[fd] = malloc(1);
		keep[fd][0] = '\0';
	}
	keep[fd] = readfile(fd, keep[fd]);
	if (!keep[fd])
	{
		free (keep[fd]);
		return (NULL);
	}
	rsline = get_this_line(keep[fd]);
	rslen = ft_strlen_n(rsline, '\n');
	keep[fd] = keep_this_line(keep[fd], rslen);
	return (rsline);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	int	i = 0;

	line = NULL;
	fd = open("/Users/psaeyang/get_next_line/test/files/42_with_nl", O_RDONLY);

	while(i < 2) 
	{		
		line = get_next_line(fd);
		printf("line %d ----|%s|\n", i, line);
		free(line);
		i++;
	}

	close(fd);
}*/
