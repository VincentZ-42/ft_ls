/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:27:39 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/08 03:34:37 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_lsflags	    init_flags(void)
{
	t_lsflags flags;

	flags.a = 0;
	flags.l = 0;
	flags.R = 0;
	flags.r = 0;
	flags.t = 0;
	flags.S = 0;
	flags.f = 0;
	flags.n = 0;
	flags.u = 0;
	flags.g = 0;
	flags.one = 0;
	flags.param_start = 1;
	return (flags);
}

static t_lsflags	set_flag(char c, t_lsflags flags)
{	
	flags.a = (c == 'a' ? 1 : flags.a);
	flags.l = (c == 'l' ? 1 : flags.l);
	flags.R = (c == 'R' ? 1 : flags.R);
	flags.r = (c == 'r' ? 1 : flags.r);
	flags.t = (c == 't' ? 1 : flags.t);
	flags.S = (c == 'S' ? 1 : flags.S);
	flags.f = (c == 'f' ? 1 : flags.f);
	flags.n = (c == 'n' ? 1 : flags.n);
	flags.u = (c == 'u' ? 1 : flags.u);
	flags.g = (c == 'g' ? 1 : flags.g);
	flags.one = (c == '1' ? 1 : flags.one);
	return (flags);
}

t_lsflags           get_ls_flags(int ac, char **av)
{
    t_lsflags flags;
    int param;
    int index;

    param = 1;
    flags = init_flags();
    if (ac > param)
    {
        while (param < ac && av[param][0] == '-' && av[param][1])
        {
            index = 1;
            while (av[param][index])
            {
                if (IS_FLAG(av[param][index]))
                    flags = set_flag(av[param][index], flags);
                else
                    ls_error(&av[param][index], FLAG_ERROR);
                index++;
            }
            param++;
            flags.param_start++;
        }
    }
    // ft_printf("alRrtSfnu1  Flag_options\n");
	// ft_printf("%d%d%d%d%d%d%d%d%d%d\n", flags.a, flags.l, flags.R, flags.r, \
	// 		flags.t, flags.S, flags.f, flags.n, flags.u, flags.one);
    return (flags);
}
