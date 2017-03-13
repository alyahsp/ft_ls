/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:30:31 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/13 19:35:08 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*get_time(t_list *lst)
{
	char *mode;

	
	return (mode);
}

char	*get_time(t_list *lst)
{
	time_t			curtime;
	char			*mtime;
	char			*times;
	char			*tmp;

	time(&curtime);
	mtime = ctime(&((t_data*)lst->content)->stats.st_mtimespec.tv_sec);
	if (((t_data*)lst->content)->stats.st_mtimespec.tv_sec - curtime < 15552000)
		times = ft_strsub(mtime, 4, 12);
	else
	{
		times = ft_strsub(mtime, 4, 7);
		tmp = times;
		times = ft_strjoin(tmp, ft_strsub(mtime, 19, 19));
		free(tmp);
	}
	return (times);
}

void	print_llst(t_list *lst, t_flags *f)
{
	struct passwd	*pwd;
	struct group	*grp;
	char			*times;
	char			*mode;

	pwd = getpwuid(((t_data*)lst->content)->stats.st_uid);
	grp = getgrgid(((t_data*)lst->content)->stats.st_gid);
	ft_printf("total %d\n", f->blocks);
	while (lst)
	{
		times = get_time(lst);
		mode = get_mode(lst);
		ft_printf("%d %s %s %d %s %s\n", ((t_data*)lst->content)->stats.st_nlink,
		pwd->pw_name, grp->gr_name, ((t_data*)lst->content)->stats.st_size,
		times, ((t_data *)(lst->content))->file_name);
		// ft_printf("%s\n", ((t_data *)(lst->content))->file_name);
		free(times);
		lst = lst->next;
	}
}

void	print_lst(t_list *lst)
{
	while (lst)
	{
		ft_printf("%s\n", ((t_data *)(lst->content))->file_name);
		lst = lst->next;
	}
}

void	ft_ls(t_list *lst, t_flags *f)
{
	lst = ft_lstsort(lst, f);
	if (!f->lflag && !f->recflag)
		print_lst(lst);
	if (f->lflag && !f->recflag)
		print_llst(lst, f);
	// else
	// {
	//
	// }
}
