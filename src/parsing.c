/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:24:26 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/07 18:59:04 by spalmaro         ###   ########.fr       */
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
}

void	get_data(char *name, t_data *data)
{
	struct stat		stats;

	// ft_printf("%d", stat(path, &stats));
	if (!lstat(path, &stats))
		ft_error(1, path);
	data->path_name = path;
}

t_list	*start_list(char *path, t_flags *flags, t_list *lst)
{
	t_data			data;
	DIR				*dirp;
	struct dirent	*file;
	t_list			*tmp;

	data = (t_data) {NULL, 0};
	if (!(dirp = opendir(path)))
		get_data(path, &data);
	while ((file = readdir(dirp)) != NULL)
		if ((file->d_name)[0] != '.' || flags->aflag == 1)
		{
			get_data(ft_strdup(file->d_name), &data);
			if (!(tmp = ft_lstnew(&data, sizeof(t_data))))
				return (NULL);
			if (!lst)
				lst = tmp;
			else
				ft_lstaddend(&lst, tmp);
		}
	return (lst);
}
// ((t_data *)(lst->content))->path_name
