/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 12:05:00 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/04 20:08:22 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "global.h"

# include <dirent.h> 		//...opendir, readdir, n closedir
# include <sys/stat.h> 		//...stat, lstat
# include <pwd.h>
# include <uuid/uuid.h>		//...getpwuid 
# include <grp.h>			//...getgrgid
# include <sys/xattr.h>		//...listxattr, getxattr
# include <time.h>			//...ctime
# include <stdlib.h>		//...malloc, free
# include <stdio.h>			//...perror
# include <string.h>		//...strerror
# include <errno.h>			//...perror, strerror
# include <stdlib.h>		//...exit
# include <stdint.h>		// need this for using uint8_t

#define LS_FLAG_OPTIONS "alRrtSfnu1"

typedef struct			s_ls_data
{
	char 				*name;
	char				*path;
	struct stat			stat;
	int					is_dir;
	struct s_ls_data	*next;
}						t_ls_data;

// You can also make a struct to hold all the flags and pass that around recursively

typedef struct			s_ls_flag
{
	int a;
	int l;
	int R;
	int r;
	int t;
	int S;
	int f;
	int n;
	int u;
	int one;
}						t_ls_flag;

void	print_long(t_ls_data *a);

t_ls_data		*ft_ls_lstnew(char *name);
void			ft_ls_addend(t_ls_data **head, t_ls_data *node);
void			ft_ls_freeall(t_ls_data *head);
int				total_size(t_ls_data *head);

t_ls_flag		get_ls_flags(int ac, char **av);

void		merge_sort(t_ls_data **list, t_ls_flag *flags);

char		*fix_path(char *c_path, char *s);

#endif
