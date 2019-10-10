/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:00:02 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/07 11:09:32 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_flag_error(char flag)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putstr_fd(flag, 2);
	ft_printf("\nusage: ls [%s] [file ...]\n", LS_FLAG_OPTIONS);
	exit (1);
}

static void	ls_dne_error(char *file)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

static void	ls_bad_file_descriptor(char *file)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": Bad file descriptor\n", 2);
}

static void	ls_access_err(char *path)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}

void		ls_error(char *path_error, int error)
{
	if (error == FLAG_ERROR)
		ls_flag_error(*path_error);
	else if (error == ENOENT)
		ls_dne_error(path_error);
	else if (error == EBADF)
		ls_bad_file_descriptor(path_error);
	else if (error == EACCES)
		ls_access_err(path_error);
}
