/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:17:55 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/20 12:55:13 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_printtype(int i)
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
}

void		get_mode(int i)
{
	char		*uid;
	char		*gid;
	char		*vtx;

	uid = (i & S_IXUSR) ? "x" : "-";
	gid = (i & S_IXGRP) ? "x" : "-";
	vtx = (i & S_IXOTH) ? "x" : "-";
	ft_printtype(i);
	ft_printf("%s%s", (i & S_IRUSR) ? "r" : "-", (i & S_IWUSR) ? "w" : "-");
	if (S_ISUID & i)
		!ft_strcmp(uid, "-") ? ft_putchar('S') : ft_putchar('s');
	else
		ft_putstr(uid);
	ft_printf("%s%s", (i & S_IRGRP) ? "r" : "-", (i & S_IWGRP) ? "w" : "-");
	if (S_ISGID & i)
		!ft_strcmp(gid, "-") ? ft_putchar('S') : ft_putchar('s');
	else
		ft_putstr(gid);
	ft_printf("%s%s", (i & S_IROTH) ? "r" : "-", (i & S_IWOTH) ? "w" : "-");
	if (S_ISVTX & i)
		!ft_strcmp(vtx, "-") ? ft_putchar('T') : ft_putchar('t');
	else
		ft_putstr(vtx);
}

char		*get_time(time_t i)
{
	time_t		curtime;
	char		*mtime;
	char		*times;
	char		*tmp;

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

int			get_blocks(t_list *lst)
{
	int			total;
	t_list		*tmp;

	total = 0;
	tmp = lst;
	while (tmp)
	{
		total += ((t_data*)tmp->content)->blocks;
		tmp = tmp->next;
	}
	return (total);
}

void		print_llst(t_list *lst, t_list *files, int check, int *fst)
{
	struct passwd	*pwd;
	struct group	*grp;

	if (lst)
	{
		pwd = getpwuid(((t_data*)lst->content)->stats.st_uid);
		grp = getgrgid(((t_data*)lst->content)->stats.st_gid);
		if (*fst && !files && check)
		{
			ft_printf("%s:\n", ((t_data*)lst->content)->recpath);
			*fst = 0;
		}
		else if (((files && ((t_data*)lst->content)->recpath) || check)
		&& !S_ISLNK(((t_data*)lst->content)->stats.st_mode))
			ft_printf("\n%s:\n", ((t_data*)lst->content)->recpath);
		if ((!files || check)
		&& !S_ISLNK(((t_data*)lst->content)->stats.st_mode))
			ft_printf("total %d\n", get_blocks(lst));
		lprinter(lst, pwd, grp);
	}
}
