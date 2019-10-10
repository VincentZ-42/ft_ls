/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:27:12 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/07 21:27:14 by vzhao            ###   ########.fr       */
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

# define LS_FLAG_OPTIONS "alRrtSfnu1"
# define FLAG_ERROR 1
# define IS_FLAG(x) (ft_strchr(LS_FLAG_OPTIONS, x) != NULL ? 1 : 0)

typedef struct      s_lsdata 
{
    char            *name;
    char            *path;
    struct stat     stat;
    struct s_lsdata *next;
}                   t_lsdata;

typedef struct      s_lsfags
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
    int param_blocks;
}                   t_lsflags;

void            ls_error(char *path_error, int error);
t_lsflags       get_ls_flags(int ac, char **av);
void            

void            bsort_av(int ac, char **av, t_lsflags flags);

#endif 