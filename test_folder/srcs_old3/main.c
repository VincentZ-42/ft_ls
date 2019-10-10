/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:27:05 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/08 00:50:42 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// void    ft_ls(char *path, t_lsflags flags, int mult_param)
// {
    
// }

int     main(int ac, char **av)
{
   int mult_param = 0;
    t_lsflags flags;
    
    flags = get_ls_flags(ac, av);
    mult_param = (ac > flags.param_skip ? 1 : 0);
/*    if (ac - flags.param_skip != 0)
    {
        ft_printf("mult_param = %d\n skip to av[%d]\n", mult_param, flags.param_skip);
        bsort_av(ac, av, flags);
        for (int i = 0; i < ac; i++)
            ft_printf("%s\n", av[i]);
    }
*/    // else
    //     ft_ls(".", flags, 0);
//    system("leaks ft_ls");
    return (0);
}
