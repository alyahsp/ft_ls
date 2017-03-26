/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:30:31 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/25 13:38:43 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	print_recpath(t_list *lst, t_list *files, int check, int *fst)
{
	if (*fst && !files && check)
	{
		ft_printf("%s:\n", ((t_data*)lst->content)->recpath);
		*fst = 0;
	}
	else if ((files && ((t_data*)lst->content)->recpath) || check)
		ft_printf("\n%s:\n", ((t_data*)lst->content)->recpath);
}

void		print_lst(t_list *lst, t_list *files, int check, int *fst)
{
	print_recpath(lst, files, check, fst);
	while (lst)
	{
		ft_printf("%s\n", ((t_data *)(lst->content))->file_name);
		lst = lst->next;
	}
}

static int	lst_maxlen(t_list *lst)
{
	int		maxlen;

	maxlen = 0;
	while (lst)
	{
		if (ft_strlen(((t_data *)(lst->content))->file_name) > maxlen)
			maxlen = ft_strlen(((t_data *)(lst->content))->file_name);
		lst = lst->next;
	}
	return (maxlen);
}

void		print_lstclm(t_list *lst, t_list *files, int check, int *fst)
{
	struct ttysize	ts;
	int				width;
	int				maxlen;
	int				tmp;

	print_recpath(lst, files, check, fst);
	ioctl(0, TIOCGWINSZ, &ts);
	maxlen = lst_maxlen(lst) + 1;
	width = ts.ts_cols / maxlen;
	while (lst)
	{
		tmp = width;
		while (lst && tmp--)
		{
			ft_printf("%s", ((t_data *)(lst->content))->file_name);
			if (tmp)
				ft_putnchar(' ', (maxlen + 1) -
				ft_strlen(((t_data *)(lst->content))->file_name));
			lst = lst->next;
		}
		ft_putchar('\n');
	}
}

void		ft_ls(t_list *lst, t_list *files, t_flags *f)
{
	int				i;
	int				first;

	i = 0;
	first = 1;
	if (lst->next)
		i = 1;
	while (lst)
	{
		lst->content = ft_lstsort(lst->content, f);
		if (!f->lflag && f->oflag)
			print_lst(lst->content, files, i, &first);
		else if (f->lflag)
			print_llst(lst->content, files, i, &first);
		else
			print_lstclm(lst->content, files, i, &first);
		if (f->recflag)
			ft_rec(lst->content, f);
		lst = lst->next;
	}
}
