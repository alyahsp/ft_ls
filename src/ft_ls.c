/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:30:31 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/18 19:28:28 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_lst(t_list *lst, t_list *files, int check, int *fst)
{
	if (*fst && !files)
	{
		ft_printf("%s:\n", ((t_data*)lst->content)->recpath);
		*fst = 0;
	}
	else if ((files && ((t_data*)lst->content)->recpath) || check)
		ft_printf("\n%s:\n", ((t_data*)lst->content)->recpath);
	while (lst)
	{
		ft_printf("%s\n", ((t_data *)(lst->content))->file_name);
		lst = lst->next;
	}
}

void	ft_ls(t_list *lst, t_list *files, t_flags *f)
{
	int i;
	int first;

	i = 0;
	first = 1;
	if (lst->next)
		i = 1;
	while (lst)
	{
		lst->content = ft_lstsort(lst->content, f);
		if (!f->lflag)
			print_lst(lst->content, files, i, &first);
		if (f->lflag)
			print_llst(lst->content, files, i, &first);
		if (f->recflag)
			ft_rec(lst->content, f);
		lst = lst->next;
	}
}
