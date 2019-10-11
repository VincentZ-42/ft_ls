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

t_lsdata			*ft_ls_lstnew(char *path, char *name)
{
	t_lsdata		*node;
	char			*temp;

	node = ft_memalloc(sizeof(t_lsdata));
	node->name = ft_strdup(name);
	node->path = ft_strdup(path);
	node->next = NULL;
	lstat(path, &node->stat);
	if (!S_ISLNK(node->stat.st_mode) && path[ft_strlen(path) - 1] != '/')
	{
		temp = ft_strjoin(path, "/");
		node->full_path = ft_strjoin(temp, name);
		free(temp);
	}
	else
		node->full_path = ft_strjoin(path, name);
	return (node);
}

void				ft_ls_addend(t_lsdata **head, t_lsdata *node)
{
	t_lsdata		*temp;

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

t_lsdata			*init_ls_list(int ac, char **av, t_lsflags flags)
{
	int				i;
	struct stat		info;
	t_lsdata		*head;
	t_lsdata		*temp;

	head = NULL;
	i = flags.param_start;
	while (i < ac)
	{
		if (lstat(av[i], &info) != -1)
		{
			temp = ft_ls_lstnew(av[i], av[i]);
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

void				ft_ls_freeall(t_lsdata *head)
{
	t_lsdata		*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void				ft_rev_list(t_lsdata **a)
{
	t_lsdata		*curr;
	t_lsdata		*prev;
	t_lsdata		*next;

	curr = *a;
	prev = NULL;
	next = NULL;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*a = prev;
}
