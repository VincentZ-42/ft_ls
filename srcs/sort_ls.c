/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:52:32 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/04 17:02:14 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		timecmp(t_ls_data *a, t_ls_data *b, t_ls_flag *flags)
{
	if (flags->u)
		return (b->stat.st_atime - a->stat.st_atime);
	else
		return (b->stat.st_mtime - a->stat.st_mtime);
}

static void	split(t_ls_data *list, t_ls_data **a, t_ls_data **b)
{
	t_ls_data *slow;
	t_ls_data *fast;

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

static t_ls_data	*sorting(t_ls_data *a, t_ls_data *b, t_ls_flag *flags)
{
	t_ls_data *ret;

	ret = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if ((flags->t ? timecmp(a, b, flags) : ft_strcmp(a->name, b->name)) <= 0)
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

void		merge_sort(t_ls_data **list, t_ls_flag *flags)
{
	t_ls_data *head;
	t_ls_data *a;
	t_ls_data *b;

	head = *list;
	if (!head || !head->next)
		return ;
	split(head, &a, &b);
	merge_sort(&a, flags);
	merge_sort(&b, flags);
	*list = sorting(a, b, flags);
}
