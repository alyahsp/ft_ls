/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:30:31 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/14 19:09:01 by spalmaro         ###   ########.fr       */
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

void	print_llst(t_list *lst, t_flags *f)
{
	struct passwd	*pwd;
	struct group	*grp;
	char			*times;
	int				nlink;

	pwd = getpwuid(((t_data*)lst->content)->stats.st_uid);
	grp = getgrgid(((t_data*)lst->content)->stats.st_gid);
	ft_printf("total %d\n", f->blocks);
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

void	print_lst(t_list *lst, t_flags *f)
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
		if (!f->lflag)
		print_lst(lst, f);
		if (f->lflag)
		print_llst(lst, f);
		if (f->recflag)
		ft_rec(lst, f);
}
