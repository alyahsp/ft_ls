/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lprinter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 22:05:21 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/25 13:36:55 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		print_fname(t_list *lst)
{
	char			buf[1000];

	if (S_ISLNK(((t_data*)lst->content)->stats.st_mode))
	{
		ft_bzero(buf, 1000);
		readlink(((t_data*)lst->content)->path, buf, 999);
		ft_printf(" %s -> %s\n", ((t_data *)(lst->content))->file_name,
		buf);
	}
	else
		ft_printf(" %s\n", ((t_data *)(lst->content))->file_name);
}

static void		print_size(t_list *lst)
{
	int				i;

	i = ((t_data*)lst->content)->stats.st_mode;
	if (S_ISCHR(i) || S_ISBLK(i))
	{
		ft_printf(" %d", major(((t_data*)lst->content)->stats.st_rdev));
		ft_printf(", %d ", minor(((t_data*)lst->content)->stats.st_rdev));
	}
	else
		ft_printf("%d ", ((t_data*)lst->content)->stats.st_size);
}

void			lprinter(t_list *lst)
{
	char			*times;
	int				nlink;
	struct passwd	*pwd;
	struct group	*grp;

	while (lst)
	{
		pwd = getpwuid(((t_data*)lst->content)->stats.st_uid);
		grp = getgrgid(((t_data*)lst->content)->stats.st_gid);
		times = get_time(((t_data*)lst->content)->stats.st_mtimespec.tv_sec);
		get_mode(((t_data*)lst->content)->stats.st_mode);
		nlink = ((t_data*)lst->content)->stats.st_nlink;
		ft_printf("  %d %s  %s  ", nlink, pwd->pw_name, grp->gr_name);
		print_size(lst);
		ft_putstr(times);
		print_fname(lst);
		free(times);
		lst = lst->next;
	}
}
