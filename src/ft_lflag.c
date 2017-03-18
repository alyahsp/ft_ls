/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:17:55 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/18 19:44:54 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	get_blocks(t_list *lst)
{
	int total;
	t_list *tmp;

	total = 0;
	tmp = lst;
	while (tmp)
	{
		total += ((t_data*)tmp->content)->blocks;
		tmp = tmp->next;
	}
	return (total);
}

void	print_llst(t_list *lst, t_list *files, int check)
{
	struct passwd	*pwd;
	struct group	*grp;
	char			*times;
	int				nlink;

	if (lst)
	{
		pwd = getpwuid(((t_data*)lst->content)->stats.st_uid);
		grp = getgrgid(((t_data*)lst->content)->stats.st_gid);
		if ((files && ((t_data*)lst->content)->recpath) || check)
			ft_printf("\n%s:\n", ((t_data*)lst->content)->recpath);
		if (S_ISDIR(((t_data*)lst->content)->stats.st_mode) || check)
			ft_printf("total %d\n", get_blocks(lst));
		while (lst)
		{
			times = get_time(((t_data*)lst->content)->stats.st_mtimespec.tv_sec);
			get_mode(((t_data*)lst->content)->stats.st_mode);
			nlink = ((t_data*)lst->content)->stats.st_nlink;
			// if (S_ISLNK(((t_data*)lst->content)->stats.st_mode))
			ft_printf("   %d  %s %s %d %s %s\n", nlink, pwd->pw_name, grp->gr_name,
			((t_data*)lst->content)->stats.st_size, times,
			((t_data *)(lst->content))->file_name);
			free(times);
			lst = lst->next;
		}
	}
}
