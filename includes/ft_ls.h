/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:20:54 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/16 22:42:26 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <errno.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_flags
{
	int				lflag;
	int				recflag;
	int				aflag;
	int				rflag;
	int				tflag;
	int				fflag;
	int				blocks;
}					t_flags;

typedef struct		s_data
{
	char			*file_name;
	char			*path;
	char			*recpath;
	struct stat		stats;
}					t_data;

void				get_flag(char *str, t_flags *flags);
void				ft_rec(t_list *lst, t_flags *f);
void				print_lst(t_list *lst, t_list *files, t_flags *f);
void				print_llst(t_list *lst, t_list *files, t_flags *f);
void				ft_fls(t_list *files, t_flags *f);
t_list				*start_flist(char *path, t_flags *flags, t_list *files);
t_list				*start_list(char *path, t_flags *flags, t_list *lst);
t_list				*ft_lstsort(t_list *lst, t_flags *f);
void				ft_error(int i, char *str);
void				ft_ls(t_list *lst, t_list *files, t_flags *flags);
void				get_mode(int i);
char				*get_time(time_t i);

#endif
