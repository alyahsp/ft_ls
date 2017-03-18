/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:26:41 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/18 19:58:51 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	sort_ascii(void *a, void *b)
{
	if (ft_strcmp(((t_data *)a)->file_name, ((t_data *)b)->file_name) > 0)
		return (0);
	return (1);
}

static int	sort_revascii(void *a, void *b)
{
	if (ft_strcmp(((t_data *)a)->file_name, ((t_data *)b)->file_name) < 0)
		return (0);
	return (1);
}

static int	sort_time(void *a, void *b)
{
	if (((t_data *)a)->stats.st_mtimespec.tv_sec <
	((t_data *)b)->stats.st_mtimespec.tv_sec)
		return (0);
	else if (((t_data *)a)->stats.st_mtimespec.tv_sec ==
	((t_data *)b)->stats.st_mtimespec.tv_sec)
	{
		if (((t_data *)a)->stats.st_mtimespec.tv_nsec <
		((t_data *)b)->stats.st_mtimespec.tv_nsec)
			return (0);
		else if (((t_data *)a)->stats.st_mtimespec.tv_nsec ==
		((t_data *)b)->stats.st_mtimespec.tv_nsec)
			return (sort_ascii(a, b));
	}
	return (1);
}

static int	sort_revtime(void *a, void *b)
{
	if (((t_data *)a)->stats.st_mtimespec.tv_sec >
	((t_data *)b)->stats.st_mtimespec.tv_sec)
		return (0);
	else if (((t_data *)a)->stats.st_mtimespec.tv_sec ==
	((t_data *)b)->stats.st_mtimespec.tv_sec)
	{
		if (((t_data *)a)->stats.st_mtimespec.tv_nsec >
		((t_data *)b)->stats.st_mtimespec.tv_nsec)
			return (0);
		else if (((t_data *)a)->stats.st_mtimespec.tv_nsec ==
		((t_data *)b)->stats.st_mtimespec.tv_nsec)
			return (sort_ascii(a, b));
	}
	return (1);
}

t_list	*ft_lstsort(t_list *lst, t_flags *f)
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
