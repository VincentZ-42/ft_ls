/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:10:46 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/07 11:10:48 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls_data	*init_ls_list(int ac, char **av, t_lsflags flags)
{
	int		i;
	struct stat	info;
	t_ls_data	*head;
	t_ls_data	*temp;

	head = NULL;
	i = flags.param_blocks + 1;
	while (i < ac)
	{
		if (lstat(av[i], &info) != -1)
		{
			temp = ft_ls_lstnew(av[i]);
			temp->stat = info;
			temp->is_dir = (S_ISDIR(info.st_mode) ? 1 : 0);
			ft_ls_addend(&head, temp);
		}
		else
		{
			ls_error(av[i], errno);
			errno = 0;
		}
		i++;
	}
	return (head);
}

t_ls_data	*ft_ls_lstnew(char *name)
{
	t_ls_data *node;

	node = ft_memalloc(sizeof(t_ls_data));
	node->name = name;
	node->next = NULL;
	return (node);
}

void		ft_ls_addend(t_ls_data **head, t_ls_data *node)
{
	t_ls_data *temp;

	temp = *head;
	if (!*head)
		(*head) = node;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
}

void		ft_ls_freeall(t_ls_data *head)
{
	t_ls_data *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int		total_size(t_ls_data *head)
{
	int total;

	total = 0;
	while (head != NULL)
	{
		total += head->stat.st_blocks;
		head = head->next;
	}
	return (total);
}

t_ls_data		*new_file(char *path, char *name)
{
	char	*temp;
	t_ls_data	*new;
	struct stat	info;

	new = (t_ls_data*)malloc(sizeof(t_ls_data));
	new->path = ft_strdup(path);
	new->name = ft_strdup(name);
	stat(path, &info);
	if (!S_ISLNK(info.st_mode) && path[ft_strlen(path) - 1] != '/')
	{
		temp = ft_strjoin(path, "/");
		new->path = ft_strjoin(temp, name);
		free(temp);
	}
	else
		new->path = ft_strjoin(path, name);
	new->next = NULL;
	return (new);
}

void	add_file(t_ls_data **head, t_ls_data *file)
{
	file->next = *head;
	*head = file;
}