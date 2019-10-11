/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 05:05:58 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/08 05:05:59 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_ls(t_lsdata *a, t_lsflags flags, int mult_param)
{
	if (a->is_dir)
		print_dir(a, flags, mult_param);
	else
		print_file(a, flags);
	ft_strsdel(3, &a->name, &a->path, &a->full_path);
}

t_lsdata		*param_input(int ac, char **av, int mult_param, t_lsflags flags)
{
	t_lsdata	*head;
	t_lsdata	*temp;

	flags.f ? 0 : bsort_av(ac, av, flags);
	head = init_ls_list(ac, av, flags);
	flags.f ? 0 : merge_sort(&head, flags);
	flags.r ? ft_rev_list(&head) : 0;
	temp = head;
	while (temp)
	{
		ft_ls(temp, flags, mult_param);
		temp = temp->next;
	}
	return (head);
}

t_lsdata		*no_arg_input(t_lsflags flags)
{
	t_lsdata	*head;
	t_lsdata	*temp;

	head = ft_ls_lstnew(".", ".");
	head->is_dir = 1;
	temp = head;
	while (temp)
	{
		ft_ls(temp, flags, 0);
		temp = temp->next;
	}
	return (head);
}

int				main(int ac, char **av)
{
	int			mult_param;
	t_lsflags	flags;
	t_lsdata	*head;

	flags = get_ls_flags(ac, av);
	mult_param = ac - flags.param_start > 1;
	if (ac - flags.param_start)
		head = param_input(ac, av, mult_param, flags);
	else
		head = no_arg_input(flags);
	if (errno == 0 && !head)
		;
	else
		(flags.one || flags.l || flags.big_r) ? 0 : ft_putchar('\n');
	ft_ls_freeall(head);
	return (0);
}
