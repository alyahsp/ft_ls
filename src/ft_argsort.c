/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:26:41 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/20 17:47:33 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	sort_ascii(void *a, void *b)
{
	if (ft_strcmp(((t_data *)((t_list *)a)->content)->recpath,
	((t_data *)((t_list *)b)->content)->recpath) > 0)
		return (0);
	return (1);
}

static int	sort_revascii(void *a, void *b)
{
	if (ft_strcmp(((t_data *)((t_list *)a)->content)->recpath,
	((t_data *)((t_list *)b)->content)->recpath) < 0)
		return (0);
	return (1);
}

t_list		*ft_argsort(t_list *lst, t_flags *f)
{
	if (f->fflag)
		return (lst);
	else if (f->tflag && f->rflag)
		return (ft_sortlst(lst, &sort_revtime));
	else if (f->tflag)
		return (ft_sortlst(lst, &sort_time));
	else if (f->rflag)
		return (ft_sortlst(lst, &sort_revascii));
	else
		return (ft_sortlst(lst, &sort_ascii));
}
