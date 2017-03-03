/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:24:26 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/03 21:02:35 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	get_flag(char *str, t_flags *flags)
{
	int			i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'l')
			flags->lflag = 1;
		else if (str[i] == 'R')
			flags->Rflag = 1;
		else if (str[i] == 'a')
			flags->aflag = 1;
		else if (str[i] == 'r')
			flags->rflag = 1;
		else if (str[i] == 't')
			flags->tflag = 1;
		else
			ft_error(0, &str[i]);
		i++;
	}
	// printf("lflag: %d, Rflag: %d, aflag: %d, rflag: %d, tflag: %d\n", flags->lflag,
	// flags->Rflag, flags->aflag, flags->rflag, flags->tflag);
}

void	get_data(char *path, t_data *data)
{
	struct stat		stats;
	struct passwd	*pwd;
	struct group	*grp;

	if (lstat(path, &stats) == -1)
		ft_error(1, path);
	if (!(pwd = getpwuid(stats.st_uid)))
		ft_error(1, path);
	grp = getgrgid(stats.st_gid);

	ft_printf("path %s\n", path);
}

void	start_list(char *path, t_flags *flags)
{
	t_data			data;
	DIR				*dirp;
	struct dirent	*file;
	t_list			*lst;
	t_list			*tmp;

	data = (t_data) {};
	if (!(dirp = opendir(path)))
		ft_error(1, path);
	while ((file = readdir(dirp)) != NULL)
	{
		if ((file->d_name)[0] != '.' || flags->aflag)
		{
			get_data(file->d_name, &data);
			if (!(tmp = ft_lstnew(&data, sizeof(t_data))))
				return ;
			if (!lst)
				lst = tmp;
			else
				ft_lstaddend(&lst, tmp);
		}
	}
	// ft_printf("dirpname %s", dirp->d_name);
	// get_data(path, flags);
}
