/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:59:02 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/04 20:08:35 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*fix_path(char *c_path, char *s)
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
