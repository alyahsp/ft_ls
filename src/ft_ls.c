/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:30:31 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/12 19:10:23 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_llst(t_list *lst, t_flags *f)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(((t_data*)lst->content)->stats.st_uid);
	grp = getgrgid(((t_data*)lst->content)->stats.st_gid);
	ft_printf("total %d\n", f->blocks);
	while (lst)
	{
		ft_printf("%d %s %s %d  %s %s\n", ((t_data*)lst->content)->stats.st_nlink,
		pwd->pw_name, grp->gr_name, ((t_data*)lst->content)->stats.st_size,
		ctime(&((t_data*)lst->content)->stats.st_mtimespec.tv_sec), ((t_data *)(lst->content))->file_name);
		// ft_printf("%s\n", ((t_data *)(lst->content))->file_name);
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
