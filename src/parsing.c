/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:24:26 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/17 19:35:42 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			get_flag(char *str, t_flags *flags)
{
	int			i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'l')
			flags->lflag = 1;
		else if (str[i] == 'R')
			flags->recflag = 1;
		else if (str[i] == 'a')
			flags->aflag = 1;
		else if (str[i] == 'r')
			flags->rflag = 1;
		else if (str[i] == 't')
			flags->tflag = 1;
		else if (str[i] == 'f')
		{
			flags->fflag = 1;
			flags->aflag = 1;
		}
		else
			ft_error(0, &str[i]);
		i++;
	}
}

static void		get_data(char *name, char *path, t_data *data, int *blk)
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
		return ;
	data->stats = stats;
	data->file_name = name;
	*blk += stats.st_blocks;
}

static t_list	*check_ifdir(char *path, t_list *files)
{
	struct stat		stats;

	if (stat(path, &stats) < 0)
	{
		ft_error(2, path);
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
	int				blocks;

	data = (t_data) {NULL, NULL, NULL, 0};
	blocks = 0;
	if (!(dirp = opendir(path)))
		return (check_ifdir(path, lst));
	while ((file = readdir(dirp)) != NULL)
		if ((file->d_name)[0] != '.' || flags->aflag == 1)
		{
			get_data(ft_strdup(file->d_name), path, &data, &blocks);
			if (!(tmp = ft_lstnew(&data, sizeof(t_data))))
				return (NULL);
			if (!lst)
				lst = tmp;
			else
				ft_lstaddend(&lst, tmp);
		}
	flags->blocks = blocks;
	closedir(dirp);
	return (lst);
}
