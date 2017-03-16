/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_flist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 21:23:02 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/16 22:41:48 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_fls(t_list *files, t_flags *f)
{
	struct passwd	*pwd;
	struct group	*grp;
	int				nlink;
	char			*times;

	files = ft_lstsort(files, f);
	pwd = getpwuid(((t_data*)files->content)->stats.st_uid);
	grp = getgrgid(((t_data*)files->content)->stats.st_gid);
	if (!f->lflag)
		print_lst(files, files, f);
	else if (f->lflag)
		print_llst(files, files, f);
}

static t_list	*check_ifdir(char *path, t_flags *f, t_list *files)
{
	struct stat		stats;
	t_data			data;
	t_list			*tmp;

	if (stat(path, &stats) < 0)
		return (NULL);
	if (S_ISDIR(stats.st_mode))
		ft_error(1, path);
	data = (t_data) {NULL, NULL, NULL, 0};
	data.file_name = path;
	data.stats = stats;
	if (!(tmp = ft_lstnew(&data, sizeof(t_data))))
		return (NULL);
	if (!files)
		files = tmp;
	else
		ft_lstaddend(&files, tmp);
	return (files);
}

t_list			*start_flist(char *path, t_flags *flags, t_list *files)
{
	t_data			data;
	DIR				*dirp;
	struct dirent	*file;
	t_list			*tmp;
	int				blocks;

	data = (t_data) {NULL, NULL, NULL, 0};
	if (!(dirp = opendir(path)))
		return (check_ifdir(path, flags, files));
	else
	{
		closedir(dirp);
		return (files);
	}
}
