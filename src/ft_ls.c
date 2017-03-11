/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:30:31 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/11 20:49:33 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// void	ft_lformat(char *path, t_data *data)
// {
// 	struct passwd	*pwd;
// 	struct group	*grp;
//
// 	if (!(pwd = getpwuid(stats.st_uid)))
// 		ft_error(1, path);
// 	grp = getgrgid(stats.st_gid);
//
// 	ft_printf("path %s\n", path);
// }

void	print_llst(t_list *lst)
{
	// ft_printf("total %d\n", ((t_data *)(lst->content))->stats->st_nlink);
	while (lst)
	{
		// ft_printf("total %d\n", ((t_data *)(lst->content))->stats->st_nlink);
		ft_printf("%s\n", ((t_data *)(lst->content))->file_name);
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
		print_llst(lst);
	// else
	// {
	//
	// }
}
