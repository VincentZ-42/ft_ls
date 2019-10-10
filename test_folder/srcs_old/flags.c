/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:00:31 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/07 11:18:13 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls_flag	init_flags(void)
{
	t_ls_flag flags;

	flags.a = 0;
	flags.l = 0;
	flags.R = 0;
	flags.r = 0;
	flags.t = 0;
	flags.S = 0;
	flags.f = 0;
	flags.n = 0;
	flags.u = 0;
	flags.one = 0;
	flags.param_skip = 1;
	return (flags);
}

t_ls_flag	set_flag(char c, t_ls_flag flags)
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
	flags.one = (c == '1' ? 1 : flags.one);
	return (flags);
}

t_ls_flag		get_ls_flags(int ac, char **av)
{
	t_ls_flag flags;
	int i;
	int j; 

	i = 0;
	flags = init_flags();
	if (ac > 1)
	{
		while (++i < ac)
		{
			j = 0;
			if (av[i][0] == '-')
			{
				j++;
				while (av[i][j])
				{
					if (ft_strchr(LS_FLAG_OPTIONS, av[i][j]))
					{
						flags = set_flag(av[i][j], flags);
						j++;
					}
					else
						ls_error(&av[i][j], FLAG_ERROR);
				}
			}
		}
	}
	ft_printf("alRrtSfnu1  Flag_options\n");
	ft_printf("%d%d%d%d%d%d%d%d%d%d\n", flags.a, flags.l, flags.R, flags.r, \
			flags.t, flags.S, flags.f, flags.n, flags.u, flags.one);
	return (flags);
}
