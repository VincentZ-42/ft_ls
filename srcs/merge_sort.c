/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 07:32:41 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/11 07:32:57 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This is merge_sort
*/

static int		timecmp(t_lsdata *a, t_lsdata *b, t_lsflags flags)
{
	if (flags.u)
		return (b->stat.st_atime - a->stat.st_atime);
	else
	{
		if (b->stat.st_mtime - a->stat.st_mtime == 0)
		{
			if (b->stat.st_mtimespec.tv_sec - a->stat.st_mtimespec.tv_sec == 0)
				return (b->stat.st_mtimespec.tv_nsec - \
				a->stat.st_mtimespec.tv_nsec);
			else
				return (b->stat.st_mtimespec.tv_sec - \
				a->stat.st_mtimespec.tv_sec == 0);
		}
		else
			return (b->stat.st_mtime - a->stat.st_mtime);
	}
}

static void		split(t_lsdata *list, t_lsdata **a, t_lsdata **b)
{
	t_lsdata	*slow;
	t_lsdata	*fast;

	slow = list;
	fast = list->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = list;
	*b = slow->next;
	slow->next = NULL;
}

static t_lsdata	*sorting(t_lsdata *a, t_lsdata *b, t_lsflags flags)
{
	t_lsdata	*ret;

	ret = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	else if ((flags.t ? timecmp(a, b, flags) : \
			ft_strcmp(a->name, b->name)) <= 0)
	{
		ret = a;
		ret->next = sorting(a->next, b, flags);
	}
	else
	{
		ret = b;
		ret->next = sorting(a, b->next, flags);
	}
	return (ret);
}

void			merge_sort(t_lsdata **list, t_lsflags flags)
{
	t_lsdata	*head;
	t_lsdata	*a;
	t_lsdata	*b;

	head = *list;
	if (!head || !head->next)
		return ;
	split(head, &a, &b);
	merge_sort(&a, flags);
	merge_sort(&b, flags);
	*list = sorting(a, b, flags);
}
