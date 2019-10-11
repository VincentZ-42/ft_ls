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

static t_lsflags	init_flags(void)
{
	t_lsflags flags;

	flags.a = 0;
	flags.l = 0;
	flags.big_r = 0;
	flags.r = 0;
	flags.t = 0;
	flags.big_s = 0;
	flags.f = 0;
	flags.n = 0;
	flags.u = 0;
	flags.o = 0;
	flags.g = 0;
	flags.one = 0;
	flags.param_start = 1;
	return (flags);
}

static t_lsflags	set_flag(char c, t_lsflags flags)
{
	flags.a = ((c == 'a' || c == 'f') ? 1 : flags.a);
	flags.l = ((c == 'l' || c == 'g' || c == 'o' || c == 'n') ? 1 : flags.l);
	flags.big_r = (c == 'R' ? 1 : flags.big_r);
	flags.r = (c == 'r' ? 1 : flags.r);
	flags.t = (c == 't' ? 1 : flags.t);
	flags.big_s = (c == 'S' ? 1 : flags.big_s);
	flags.f = (c == 'f' ? 1 : flags.f);
	flags.n = (c == 'n' ? 1 : flags.n);
	flags.u = (c == 'u' ? 1 : flags.u);
	flags.o = (c == 'o' ? 1 : flags.o);
	flags.g = (c == 'g' ? 1 : flags.g);
	if (c == '1')
	{
		flags.one = 1;
		flags.l = 0;
	}
	return (flags);
}

t_lsflags			get_ls_flags(int ac, char **av)
{
	t_lsflags		flags;
	int				param;
	int				index;

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
	return (flags);
}
