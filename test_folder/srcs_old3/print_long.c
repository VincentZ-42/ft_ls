/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 10:58:02 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/07 10:34:45 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_file_type(t_ls_data *a)
{
	if (S_ISREG(a->stat.st_mode))
		ft_putchar('-');
	else if (S_ISDIR(a->stat.st_mode))
		ft_putchar('d');
	else if (S_ISCHR(a->stat.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(a->stat.st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(a->stat.st_mode))
		ft_putchar('p');
	else if (S_ISLNK(a->stat.st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(a->stat.st_mode))
		ft_putchar('s');
}

void		print_mode(t_ls_data *a)
{
	print_file_type(a);
	ft_putchar(a->stat.st_mode & S_IRUSR ? 'r' : '-');
	ft_putchar(a->stat.st_mode & S_IWUSR ? 'w' : '-');
	ft_putchar(a->stat.st_mode & S_IXUSR ? 'x' : '-');
	ft_putchar(a->stat.st_mode & S_IRGRP ? 'r' : '-');
	ft_putchar(a->stat.st_mode & S_IWGRP ? 'w' : '-');
	ft_putchar(a->stat.st_mode & S_IXGRP ? 'x' : '-');
	ft_putchar(a->stat.st_mode & S_IROTH ? 'r' : '-');
	ft_putchar(a->stat.st_mode & S_IWOTH ? 'w' : '-');
	ft_putchar(a->stat.st_mode & S_IXOTH ? 'x' : '-');
	if (listxattr(a->path, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_putchar('@');
	else
		ft_putchar(' ');
}

/*
 * getpwuid and getgrgid accesses the struct containing the owner and group names
 * using the information in the stat
 * Since we only need the owner and group name, we just pull this info and print it
*/ 

void		print_names(t_ls_data *a)
{
	char *owner_name;
	char *group_name;

	// add bonus for g flag here
	owner_name = getpwuid(a->stat.st_uid)->pw_name;
	group_name = getgrgid(a->stat.st_gid)->gr_name;
	ft_printf("%-6s ", owner_name);
	ft_printf("%-9s ", group_name);
}

void		print_time(t_ls_data *a)
{
	char *time;

	// Need to add condition, if last access was more than 6 months, only use year time....
	time = ctime(&a->stat.st_mtime);
	time[16] = '\0';				// set this to null char to cut out the seconds and year
	ft_printf("%s ", time + 4);		// start at index 4 because we don't need to post day
	//-u flag bonus used here
}

void		print_long(t_ls_data *a)
{
	print_mode(a);
	ft_printf("%d ", a->stat.st_nlink);
	print_names(a);
	if (!S_ISBLK(a->stat.st_mode) && !S_ISCHR(a->stat.st_mode))
		ft_printf("%6lld ", a->stat.st_size);
	else
		ft_printf("%4u, %4u", major(a->stat.st_rdev), minor(a->info.st_rdev));
	print_time(a);
//	ft_printf("%s\n", a->name);
}

void		print_link(char *path)
{
	char	*link;

	link = ft_strnew(PATH_MAX);
	readlink(path, link, PATH_MAX);
	ft_putstr(link);
	free(link);
}
