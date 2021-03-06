/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:20:54 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/25 13:39:48 by spalmaro         ###   ########.fr       */
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
# include <sys/ioctl.h>
# include "../libft/libft.h"

typedef struct		s_flags
{
	int				lflag;
	int				recflag;
	int				aflag;
	int				rflag;
	int				tflag;
	int				fflag;
	int				oflag;
}					t_flags;

typedef struct		s_data
{
	char			*file_name;
	char			*path;
	char			*recpath;
	int				blocks;
	struct stat		stats;
}					t_data;

void				get_flag(char *str, t_flags *flags, int i);
void				ft_rec(t_list *lst, t_flags *f);
void				print_lst(t_list *lst, t_list *files, int check, int *fst);
void				print_llst(t_list *lst, t_list *files, int check, int *fst);
void				ft_fls(t_list *files, t_flags *f);
void				lprinter(t_list *lst);
t_list				*get_list(char **argv, t_list *lst, int *check, t_flags *f);
t_list				*get_flst(char **argv, t_list *fls, t_flags *flags);
t_list				*start_list(char *path, t_flags *flags, t_list *lst);
t_list				*ft_lstsort(t_list *lst, t_flags *f);
t_list				*ft_argsort(t_list *lst, t_flags *f);
void				print_lstclm(t_list *lst, t_list *files, int check,
					int *fst);
void				ft_error(int i, char *str);
void				ft_ls(t_list *lst, t_list *files, t_flags *flags);
void				get_mode(int i);
char				*get_time(time_t i);
int					check_iflink(char *path);
int					get_blocks(t_list *lst);
int					sort_time(void *a, void *b);
int					sort_revtime(void *a, void *b);

#endif
