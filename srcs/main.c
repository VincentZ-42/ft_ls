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

static void     ft_ls(t_lsdata *a, t_lsflags flags, int mult_param)
{
    if (a->is_dir)
        print_dir(a, flags, mult_param);
    else
        print_file(a, flags);
    ft_strsdel(3, &a->name, &a->path, &a->full_path);
}

int             main(int ac, char **av)
{
    int         mult_param;
    t_lsflags   flags;
    t_lsdata    *head;
    t_lsdata    *temp;

    flags = get_ls_flags(ac, av);
    mult_param = ac - flags.param_start > 1;
    // ft_printf("param_start = %d\nmult_param = %d\n", flags.param_start, mult_param);
    if (ac - flags.param_start)
    {
        // bonus -f option here
        flags.f ? 0 : bsort_av(ac, av, flags);
        head = init_ls_list(ac, av, flags);
        flags.f ? 0 : merge_sort(&head, flags);
        temp = head;
        while (temp)
        {
            ft_ls(temp, flags, mult_param);
            temp = temp->next;
            if (temp != NULL)          
                if (temp->is_dir && mult_param)
                    ft_putchar('\n');
        }
    }
    else
    {
        // head = get_dir_list(ft_strdup("."), flags);
        head = ft_ls_lstnew(".", ".");
        head->is_dir = 1;
        temp = head;
        while (temp)
        {
            ft_ls(temp, flags, 0);
            temp = temp->next;
        }
    }
    ft_ls_freeall(head);
    // system("leaks ft_ls");
    return (0);
}