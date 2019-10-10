/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 00:53:21 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/08 05:05:55 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void        ft_ls(t_ls_data *path, t_lsflags flags, int multiple)
{
    if (path->is_dir == 1)
        print_dir(path, flags, multiple);
    else
        print_file(path, path->name, flags);
}

int         main(int ac, char **av)
{
    t_lsflags   flags;
    int         mult_param;
    t_ls_data   *head;
    t_ls_data   *temp;
    flags = get_ls_flags(ac, av);
    mult_param = ac - (flags.param_blocks) > 1;
    ft_printf("param_blocks = %d\nmult_param = %d\n", flags.param_blocks, mult_param);
    if (ac - (flags.param_blocks + 1) != 0)
    {
        flags.f ? 0 : bsort_args(ac, av, flags);
        head = init_ls_list(ac, av, flags);
        if (flags.t && !flags.f)
            merge_sort(&head, &flags);
        temp = head;
        while (temp)
        {
            ft_ls(temp, flags, mult_param);
            temp = temp->next;
        }
        ft_ls_freeall(head);
    }
    // system("leaks ft_ls");
    return (0);
}
