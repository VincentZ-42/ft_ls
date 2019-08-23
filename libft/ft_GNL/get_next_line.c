/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:16:16 by vzhao             #+#    #+#             */
/*   Updated: 2019/08/23 13:49:42 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_linecall(const int fd, char **line, char **s)
{
	int				i;
	char			*temp;

	i = 0;
	while (s[fd][i] && s[fd][i] != '\n')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		temp = ft_strdup(s[fd] + i + 1);
		ft_strdel(&s[fd]);
		s[fd] = temp;
	}
	else
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*s[MAX_FD];
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*temp;

	ERROR(fd < 0 || !line || fd > MAX_FD);
	if (!s[fd])
		s[fd] = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = ft_strjoin(s[fd], buf);
		ft_strdel(&s[fd]);
		s[fd] = temp;
		BREAK(ft_strchr(s[fd], '\n'));
	}
	ERROR(ret < 0);
	FINISHED(ret == 0 && s[fd][0] == '\0');
	return (get_next_linecall(fd, line, s));
}
