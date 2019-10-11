/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 10:58:02 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/08 03:30:57 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_file_type(t_lsdata *a)
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

void		print_mode(t_lsdata *a)
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
** getpwuid and getgrgid accesses the struct  ...
** ... containing the owner and group names ...
** using the information in the stat
** Since we only need the owner and group name, ...
** we just pull this info and print it
*/

void		print_names(t_lsdata *a, t_lsflags flags)
{
	char	*owner_name;
	char	*group_name;
	uid_t	user_id;
	gid_t	grp_id;

	if (flags.n)
	{
		user_id = getpwuid(a->stat.st_uid)->pw_uid;
		grp_id = getgrgid(a->stat.st_gid)->gr_gid;
		flags.g ? 0 : ft_printf("%-6u ", user_id);
		flags.o ? 0 : ft_printf("%-9u ", grp_id);
	}
	else
	{
		owner_name = getpwuid(a->stat.st_uid)->pw_name;
		group_name = getgrgid(a->stat.st_gid)->gr_name;
		flags.g ? 0 : ft_printf("%-6s ", owner_name);
		flags.o ? 0 : ft_printf("%-9s ", group_name);
	}
}

/*
** Comment applies to print_time function below....
** Need to add condition, if last access > 6 moths, only use year time...
** time[16] is set to null char to cut out the seconds and year
** start at time + 4 bcuz we don't need to post day
*/

void		print_time(t_lsdata *a, t_lsflags flags)
{
	char	*time;

	if (flags.u && flags.l)
		time = ctime(&a->stat.st_atime);
	else
		time = ctime(&a->stat.st_mtime);
	time[16] = '\0';
	ft_printf("%s ", time + 4);
}

void		print_long(t_lsdata *a, t_lsflags flags)
{
	print_mode(a);
	ft_printf("%3d ", a->stat.st_nlink);
	print_names(a, flags);
	if (!S_ISBLK(a->stat.st_mode) && !S_ISCHR(a->stat.st_mode))
		ft_printf("%6lld ", a->stat.st_size);
	else
		ft_printf("%4u, %4u", major(a->stat.st_rdev), minor(a->stat.st_rdev));
	print_time(a, flags);
}
