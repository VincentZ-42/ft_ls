/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:38:14 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/07 11:18:17 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(char *path, t_ls_flag *flags)
{
/*
 * make a list from the indicated path
 * send list and flags into a printing function that handles flags n sorting
 * if -R flag, check list for next direction and use a recursive while loop until no more directories
*/
}

int		main(int ac, char **av)
{
	DIR *dp = NULL;
	struct dirent *dptr = NULL;
	t_ls_data *head;
	t_ls_data *temp;
	t_ls_flag flags;

	flags = get_ls_flags(ac, av);
	dp = opendir(".");
//	if (ac == 1)
//		ft_ls(".", &flags);
	if (ac > 1)
	{
		while (NULL != (dptr = readdir(dp)))
		{
			temp = ft_ls_lstnew(dptr->d_name);
			ft_ls_addend(&head, temp);
			stat(temp->name, &temp->stat);
			temp->is_dir = (S_ISDIR(temp->stat.st_mode)) ? 1: 0;

//			if (dptr->d_name[0] != '.')
//			{
//				info->name = dptr->d_name;
//				stat(info->name, &info->stat);
//				print_long(info);
//			}

		}
		merge_sort(&head, &flags);
		temp = head;
		int sum = total_size(temp);  // This sum includes all hidden files as well....
		printf("total %d\n", sum);
		while (temp != NULL)
		{
			print_long(temp);
		//	ft_printf("%s\n", temp->name);
			temp = temp->next;
		}
		ft_printf("testing: %s\n", fix_path("testing", "123"));
		ft_ls_freeall(head);
//		closedir(dp);
	}
//	else
//		perror("Did not work\n");
//	system("leaks ft_ls");
	return (0);
}
