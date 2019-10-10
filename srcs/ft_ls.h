/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 04:57:41 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/08 05:03:48 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/global.h"

# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <errno.h>
# include <stdint.h>
# include <limits.h>

# define LS_FLAG_OPTIONS "alRrtSfnug1"
# define FLAG_ERROR 1
# define IS_FLAG(x) (ft_strchr(LS_FLAG_OPTIONS, x) != NULL ? 1 : 0)

typedef struct		s_lsdata
{
	char			*name;
	char			*path;
	char			*full_path;
	struct stat		stat;
	int				is_dir;
	struct s_lsdata	*next;
}					t_lsdata;

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
	int param_start;
}                       t_lsflags;

t_lsflags				get_ls_flags(int ac, char **av);
void					ls_error(char *path_error, int error);
void					bsort_av(int ac, char **av, t_lsflags flags);
void					merge_sort(t_lsdata **list, t_lsflags flags);

t_lsdata				*init_ls_list(int ac, char **av, t_lsflags flags);
t_lsdata				*ft_ls_lstnew(char *path, char *name);
t_lsdata				*new_file(char *path, char *name);
t_lsdata				*get_dir_list(char *path, t_lsflags flags);
void		ft_ls_addend(t_lsdata **head, t_lsdata *node);
void					ft_ls_freeall(t_lsdata *head);
void					print_long(t_lsdata *a);
void					print_link(char *path);
int						total_size(t_lsdata *head);
void					print_file(t_lsdata *a, t_lsflags flags);
void					print_dir(t_lsdata *a, t_lsflags flags, int mult_param);

char					*fix_path(char *c_path, char *s);

#endif 