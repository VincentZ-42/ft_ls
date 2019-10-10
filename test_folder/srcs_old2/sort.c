/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:27:31 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/07 21:27:33 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void     ft_swap(char **a, char **b)
{
    char *temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void    bsort_av(int ac, char **av, t_lsflags flags)
{
    int i;

    i = flags.param_skip;
    while (i + 1 < ac)
    {
        if (!flags.r && ft_strcmp(av[i], av[i + 1]) > 0)
        {
            ft_swap(&av[i], &av[i + 1]);
            i = flags.param_skip;
        }
        else if (!flags.r && ft_strcmp(av[i], av[i + 1]) < 0)
        {
            ft_swap(&av[i], &av[i + 1]);
            i = flags.param_skip;
        }
        else
            i++;
    }
}
