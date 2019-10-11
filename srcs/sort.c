/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 01:11:49 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/08 01:11:51 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This is bubble sort
*/

static void		arg_swap(char **a, char **b)
{
	char		*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void			bsort_av(int ac, char **av, t_lsflags flags)
{
	int			i;

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
