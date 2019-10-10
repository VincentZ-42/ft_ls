/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 03:02:10 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/08 03:34:02 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    print_file(t_ls_data *path, char *full_path, t_lsflags flags)
{
    if (flags.l)
        print_long(path);
    ft_printf("%s", path->name);
    if (flags.l && S_ISLNK(path->stat.st_mode))
    {
        ft_putstr(" -> ");
        print_link(full_path);
    }
    ft_putchar('\n');
    if (full_path)
        ;
    if (flags.a)
        ;
    // ft_printf("print_file\n");
}

t_ls_data   *get_dir(char *path, t_lsflags flags)
{
    DIR     *stream;
    struct dirent   *dir;
    t_ls_data       *head;
    t_ls_data       *temp;

    head = NULL;
    errno = 0;
    if (!(stream = opendir(path)))
    {
        ls_error(path, EACCES);
        return (NULL);
    }
    while ((dir = readdir(stream)))
    {
        if (dir->d_name[0] != '.' || dir->d_name[0] == '.' && flags.a)
        {
            temp = new_file(path, dir->d_name);
            add_file(&head, temp);
        }
    }
    if (!flags.f)
        merge_sort(&head, &flags);
    closedir(stream);
    return (head);
}

static void     recur_and_free(t_ls_data *head, t_lsflags flags)
{
    t_ls_data   *temp;
    t_ls_data   *del;

    temp = head;
    while (temp)
    {
        if (!(ft_strequ(".", temp->name) || ft_strequ("..", temp->name)))
        {
            if ((temp->is_dir == 1) || S_ISLNK(a->stat.st_mode) && flags.R)
                print_dir(temp->path, flags, 1);
        }
    }
    del = temp;
    temp = temp->next;
    free(del);
}

void    print_dir(t_ls_data *path, t_lsflags flags, int multiple)
{
    t_ls_data *head;
    t_ls_data *temp;

    if (multiple)
        ft_printf("%s:\n", path->name);
    head = get_dir(path->name, flags);
    if (flags.l)
        ft_printf("total %d\n", total_size(head));
    temp = head;
    if (!head && errno == 0)
        ft_putchar('\n');
    else
    {
        while (temp)
        {
            lstat(temp->path, &info);
            print_file(temp->path, temp->name, flags);
            temp = temp->next;
            if (!temp && multiple)
                ft_putstr("\n");
        }
        recur_and_free(head, flags);
    }
    if (flags.a)
        ;

    // ft_printf("print_dir\n");
}
