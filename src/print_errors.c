/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:58:45 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/20 17:39:17 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				check_iflink(char *path)
{
	struct stat		stats;

	if (lstat(path, &stats) < 0)
		return (0);
	if (S_ISLNK(stats.st_mode))
		return (1);
	return (0);
}

static int		get_data(char *name, char *path, t_data *data)
{
	struct stat		stats;
	char			*tmp;

	data->recpath = path;
	if (ft_strcmp(".", name) || ft_strcmp("..", name))
	{
		tmp = ft_strjoin(path, "/");
		path = ft_strjoin(tmp, name);
		data->path = path;
	}
	free(tmp);
	if (lstat(path, &stats) < 0)
	{
		ft_error(1, name);
		return (0);
	}
	data->file_name = name;
	data->stats = stats;
	data->blocks = stats.st_blocks;
	return (1);
}

static t_list	*check_ifdir(char *path, t_list *files)
{
	struct stat		stats;
	struct stat		lstats;

	if (stat(path, &stats) < 0 && lstat(path, &stats) < 0)
	{
		ft_error(1, path);
		return (files);
	}
	if (S_ISDIR(stats.st_mode))
	{
		ft_error(1, path);
		return (files);
	}
	return (files);
}

t_list			*start_list(char *path, t_flags *flags, t_list *lst)
{
	t_data			data;
	DIR				*dirp;
	struct dirent	*file;
	t_list			*tmp;

	data = (t_data) {NULL, NULL, NULL, 0, 0};
	if (flags->lflag && check_iflink(path))
		return (lst);
	if (!(dirp = opendir(path)))
		return (check_ifdir(path, lst));
	while ((file = readdir(dirp)) != NULL)
		if ((file->d_name)[0] != '.' || flags->aflag == 1)
		{
			if (get_data(ft_strdup(file->d_name), path, &data))
			{
				if (!(tmp = ft_lstnew(&data, sizeof(t_data))))
					return (NULL);
				if (!lst)
					lst = tmp;
				else
					ft_lstaddend(&lst, tmp);
			}
		}
	closedir(dirp);
	return (lst);
}

t_list			*get_list(char **argv, t_list *lst, int argc, t_flags *f)
{
	int			i;
	int			k;

	i = 1;
	k = 1;
	while (argv[i])
	{
		if ((argv[i][0] == '-' && argv[i][1] != '-') && check == 0)
			k++;
		i++;
	}
	while (argv[k])
	{
		while ()
	}
	return (fls);
}
