/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 01:11:49 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/08 01:11:51 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// This is bubble sort

static void    arg_swap(char **a, char **b)
{
    char *temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void    bsort_av(int ac, char **av, t_lsflags flags)
{
    int i;

    i = flags.param_start;
    while (i + 1 < ac)
    {
        if (!flags.r && ft_strcmp(av[i], av[i + 1]) > 0)
        {
            arg_swap(&av[i], &av[i + 1]);
            i = flags.param_start;
        }
        else if (flags.r && ft_strcmp(av[i], av[i + 1]) < 0)
        {
            arg_swap(&av[i], &av[i + 1]);
            i = flags.param_start;
        }
        else
            i++;
    }
}

// This is merge_sort

static int		timecmp(t_lsdata *a, t_lsdata *b, t_lsflags flags)
{
	if (flags.u)
		return (b->stat.st_atime - a->stat.st_atime);
	else
		return (b->stat.st_mtime - a->stat.st_mtime);
}

static void	split(t_lsdata *list, t_lsdata **a, t_lsdata **b)
{
	t_lsdata *slow;
	t_lsdata *fast;

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
	t_lsdata *ret;

	ret = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if ((flags.t ? timecmp(a, b, flags) : ft_strcmp(a->name, b->name)) <= 0)
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

void		merge_sort(t_lsdata **list, t_lsflags flags)
{
	t_lsdata *head;
	t_lsdata *a;
	t_lsdata *b;

	head = *list;
	if (!head || !head->next)
		return ;
	split(head, &a, &b);
	merge_sort(&a, flags);
	merge_sort(&b, flags);
	*list = sorting(a, b, flags);
}