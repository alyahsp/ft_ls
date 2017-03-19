/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 12:07:56 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/19 17:15:57 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_rec(t_list *lst, t_flags *f)
{
	t_list	*ndir;
	int		check;

	ndir = NULL;
	check = 0;
	// if (((t_data*)lst->content)->file_name)
		while (lst)
		{
			if (ft_strcmp(".", ((t_data*)lst->content)->file_name)
			&& ft_strcmp("..", ((t_data*)lst->content)->file_name))
				if (S_ISDIR(((t_data*)lst->content)->stats.st_mode))
				{
					ft_printf("\n%s:\n", ((t_data *)lst->content)->path);
					ndir = ft_lstnew(start_list(((t_data*)lst->content)->path,
					f, ndir), sizeof(t_list));
					ft_ls(ndir, NULL, f);
					ft_memdel((void **)&ndir);
				}
			lst = lst->next;
		}
	// else
	// 	ft_error(1, ((t_data*)lst->content)->path);
}
