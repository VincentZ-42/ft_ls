/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:38:14 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/03 20:07:57 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
 * Read the flags and then sort files and directories
 * -- May store directories into a struct and all files n dirs into a different struct 
 * Then call ft_ls recursively and readjust the path
*/ 


int		main(int ac, char **av)
{
	DIR *dp = NULL;
	struct dirent *dptr = NULL;
//	int sum = 0;
	t_ls_data *head;
	t_ls_data *temp;
	t_ls_flag flags;

	flags = get_ls_flags(ac, av);
	dp = opendir(".");
	if (ac >= 1)
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
//				sum += info->stat.st_blocks;
//				print_long(info);
//			}

		}
//		ft_printf("total %d\n", sum);
		temp = head;
		while (temp != NULL)
		{
			print_long(temp);
			temp = temp->next;
		}
		ft_ls_freeall(head);
		closedir(dp);
	}
	else
		perror("Did not work\n");
//	system("leaks ft_ls");
	return (0);
}
