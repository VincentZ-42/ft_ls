/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 00:53:59 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/08 05:04:19 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/global.h"

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
# include <limits.h>		// need this for PATH_MAX

# define LS_FLAG_OPTIONS "alRrtSfnug1"
# define FLAG_ERROR 1
# define IS_FLAG(x) (ft_strchr(LS_FLAG_OPTIONS, x) != NULL ? 1 : 0)

typedef struct          s_ls_data
{
    char                *name;
    char                *path;
    struct stat         stat;
    int                 is_dir;
    struct s_ls_data    *next;
}                       t_ls_data;

typedef struct          s_lsflags
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
    int g;
	int one;
	int param_blocks;
}                       t_lsflags;

t_lsflags   get_ls_flags(int ac, char **av);
void        ls_error(char *path_error, int error);
void        bsort_args(int ac, char **av, t_lsflags flags);

t_ls_data   *init_ls_list(int ac, char **av, t_lsflags flags);
t_ls_data   *ft_ls_lstnew(char *name);
void        ft_ls_addend(t_ls_data **head, t_ls_data *node);
void        ft_ls_freeall(t_ls_data *head);

int         total_size(t_ls_data *head);

void        merge_sort(t_ls_data **list, t_lsflags *flags);

void        print_dir(t_ls_data *path, t_lsflags flags, int multiple);
void        print_file(t_ls_data *path, char *full_path, t_lsflags flags);

void        print_long(t_ls_data *a);
void        print_link(char *path);
t_ls_data   *get_dir(char *path, t_lsflags flags);


#endif
