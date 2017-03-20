/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lprinter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 22:05:21 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/19 22:33:22 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		print_fname(t_list *lst)
{
	char	buf[1000];

	if (S_ISLNK(((t_data*)lst->content)->stats.st_mode))
	{
		ft_bzero(buf, 1000);
		readlink(((t_data*)lst->content)->path, buf, 999);
		ft_printf(" %s -> %s\n", ((t_data *)(lst->content))->file_name,
		buf);
	}
	else
		ft_printf(" %s\n", ((t_data *)(lst->content))->file_name);
}

static void		print_size(t_list *lst)
{
	int		i;

	i = ((t_data*)lst->content)->stats.st_mode;
	if (S_ISCHR(i) || S_ISBLK(i))
	{
		ft_printf(" %d", minor(((t_data*)lst->content)->stats.st_rdev));
		ft_printf(", %d ", major(((t_data*)lst->content)->stats.st_rdev));
	}
	else
		ft_printf("%d ", ((t_data*)lst->content)->stats.st_size);
}

// static void		print_acl(t_list *lst)
// {
// 	acl_t	tmp;
// 	char	buf[100];
//
// 	if (listxattr(path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
// 		ft_putchar('@');
// 	else if ((tmp = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
// 	{
// 		acl_free(tmp);
// 		ft_putchar('+');
// 	}
// 	else
// 		ft_putchar(' ');
// }

void		lprinter(t_list *lst, struct passwd *pwd, struct group *grp)
{
	char	*times;
	int		nlink;

	while (lst)
	{
		times = get_time(((t_data*)lst->content)->stats.st_mtimespec.tv_sec);
		get_mode(((t_data*)lst->content)->stats.st_mode);
		print_acl(lst);
		nlink = ((t_data*)lst->content)->stats.st_nlink;
		ft_printf("  %d %s  %s  ", nlink, pwd->pw_name, grp->gr_name);
		print_size(lst);
		ft_putstr(times);
		print_fname(lst);
		free(times);
		lst = lst->next;
	}
}
