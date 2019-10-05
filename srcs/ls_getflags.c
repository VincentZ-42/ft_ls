/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:42:42 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/04 17:03:23 by vzhao            ###   ########.fr       */
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

void		print_invalid_flag(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_printf("usage: ./ft_ls [-alRrtSfnu] [file ...]\n");
	exit (0);
}

// Function works but does not work if you list a file or directory before the invalid flag....
// maybe have to account for it later

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
						print_invalid_flag(av[i][j]);
				}
			}
		}
	}
	ft_printf("alRrtSfnu1  Flag_options\n");
	ft_printf("%d%d%d%d%d%d%d%d%d%d\n", flags.a, flags.l, flags.R, flags.r, \
			flags.t, flags.S, flags.f, flags.n, flags.u, flags.one);
	return (flags);
}
