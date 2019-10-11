/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:23:47 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/08 14:23:51 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				gdl_body(char *n, char *p, t_lsdata **head, t_lsflags flags)
{
	t_lsdata		*temp;
	char			*temp_path;
	struct stat		info;

	if (n[0] != '.' || (flags.a && n[0] == '.'))
	{
		temp_path = fix_path(p, n);
		temp = ft_ls_lstnew(temp_path, n);
		if (lstat(temp_path, &info) != -1)
		{
			temp->stat = info;
			temp->is_dir = (S_ISDIR(info.st_mode) ? 1 : 0);
		}
		else
		{
			ls_error(temp_path, errno);
			errno = 0;
		}
		ft_ls_addend(head, temp);
		ft_strdel(&temp_path);
	}
}

t_lsdata			*get_dir_list(char *path, t_lsflags flags)
{
	DIR				*dptr;
	struct dirent	*dir;
	t_lsdata		*head;

	head = NULL;
	errno = 0;
	if ((dptr = opendir(path)) == NULL)
	{
		ls_error(path, EACCES);
		return (NULL);
	}
	while ((dir = readdir(dptr)) != NULL)
		gdl_body(dir->d_name, path, &head, flags);
	flags.f ? 0 : merge_sort(&head, flags);
	flags.r ? ft_rev_list(&head) : 0;
	closedir(dptr);
	return (head);
}

void				print_file(t_lsdata *a, t_lsflags flags)
{
	if (flags.l)
		print_long(a, flags);
	if (flags.l && S_ISLNK(a->stat.st_mode))
	{
		ft_putstr(a->name);
		ft_putstr(" -> ");
		print_link(a->path);
	}
	else
		ft_printf("%-18s", a->name);
	(flags.one || flags.l) ? ft_putchar('\n') : 0;
}

static void			ls_get_next_call(t_lsdata *a, t_lsflags flags)
{
	t_lsdata		*temp;
	t_lsdata		*del;

	temp = a;
	if (flags.big_r)
		ft_putchar('\n');
	while (temp)
	{
		if (!(ft_strequ(".", temp->name) || ft_strequ("..", temp->name)))
		{
			if (flags.big_r == 1 && temp->is_dir)
				print_dir(temp, flags, 1);
		}
		del = temp;
		temp = temp->next;
		ft_strsdel(3, &del->name, &del->path, &del->full_path);
		free(del);
	}
}

void				print_dir(t_lsdata *a, t_lsflags flags, int mult_param)
{
	t_lsdata		*head;
	t_lsdata		*temp;

	if (mult_param && flags.big_r & !flags.l)
		ft_putchar('\n');
	if (mult_param)
		ft_printf("%s:\n", a->path);
	head = get_dir_list(a->path, flags);
	if (flags.l && head)
		ft_printf("total %d\n", total_size(head));
	temp = head;
	if (!head && errno == 0)
		ft_putchar('\n');
	else
	{
		while (temp)
		{
			print_file(temp, flags);
			temp = temp->next;
		}
		temp = head;
		ls_get_next_call(temp, flags);
	}
}
