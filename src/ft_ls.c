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

void	get_mode(int i)
{
	if (S_ISDIR(i))
		ft_putchar('d');
	else if (S_ISCHR(i))
		ft_putchar('c');
	else if (S_ISBLK(i))
		ft_putchar('b');
	else if (S_ISLNK(i))
		ft_putchar('l');
	else if (S_ISSOCK(i))
		ft_putchar('s');
	else if (S_ISFIFO(i))
		ft_putchar('p');
	else
		ft_putchar('-');
	ft_printf("%s%s%s%s%s%s%s", (i & S_IRUSR) ? "r" : "-",
	(i & S_IWUSR) ? "w" : "-", (i & S_IXUSR) ? "x" : "-",
	(i & S_IRGRP) ? "r" : "-", (i & S_IWGRP) ? "w" : "-",
	(i & S_IXGRP) ? "x" : "-", (i & S_IROTH) ? "r" : "-",
	(i & S_IWOTH) ? "w" : "-", (i & S_IXOTH) ? "x" : "-");
}

char	*get_time(time_t i)
{
	time_t			curtime;
	char			*mtime;
	char			*times;
	char			*tmp;

	time(&curtime);
	mtime = ctime(&i);
	if (i - curtime < 15552000)
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

void	print_lst(t_list *lst, t_list *files, int check)
{
	if ((files && ((t_data*)lst->content)->recpath) || check)
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

	i = 0;
	if (lst->next)
		i = 1;
	while (lst)
	{
		lst->content = ft_lstsort(lst->content, f);
		if (!f->lflag)
			print_lst(lst->content, files, i);
		if (f->lflag)
			print_llst(lst->content, files, i);
		if (f->recflag)
			ft_rec(lst->content, f);
		lst = lst->next;
	}
}
