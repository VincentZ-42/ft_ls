/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 07:53:56 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/11 07:54:06 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			total_size(t_lsdata *head)
{
	int		total;

	total = 0;
	while (head != NULL)
	{
		total += head->stat.st_blocks;
		head = head->next;
	}
	return (total);
}

void		print_link(char *path)
{
	char	*link;

	link = ft_strnew(PATH_MAX);
	readlink(path, link, PATH_MAX);
	ft_putstr(link);
	free(link);
}

char		*fix_path(char *c_path, char *s)
{
	char	*temp;
	char	*new_path;

	if (!s)
	{
		if (c_path[0] == '~' || c_path[0] == '/' || c_path[0] == '.')
			return (ft_strdup(c_path));
		return (ft_strjoin("./", c_path));
	}
	temp = ft_strjoin(c_path, "/");
	new_path = ft_strjoin(temp, s);
	free(temp);
	return (new_path);
}
