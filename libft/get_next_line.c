/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:28:20 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/08 20:26:18 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fill_line(char **line, char **str)
{
	int		ret;
	char	*tmp;

	ret = 0;
	if ((tmp = ft_strchr(*str, '\n')))
	{
		*tmp = '\0';
		if (!(*line = ft_strdup(*str)))
			return (-1);
		tmp++;
		ft_strcpy(*str, tmp);
		ret = 1;
	}
	else if (ft_strlen(*str))
	{
		if (!(*line = ft_strdup(*str)))
			return (-1);
		**str = '\0';
		ret = 1;
	}
	else if (!(*line = ft_strnew(0)))
		return (-1);
	return (ret);
}

static int	read_from_fd(t_file *gnl_content)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	while (!ft_strchr(gnl_content->str, '\n'))
	{
		ft_bzero(buf, BUFF_SIZE + 1);
		if ((ret = read(gnl_content->fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		if (!ret)
			return (0);
		tmp = gnl_content->str;
		gnl_content->str = ft_strjoin(gnl_content->str, buf);
		free(tmp);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*gnl;
	t_list			*tmp_lst;
	t_file			gnl_content;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	tmp_lst = gnl;
	while (tmp_lst && (((t_file *)(tmp_lst->content))->fd != fd))
		tmp_lst = tmp_lst->next;
	if (!tmp_lst)
	{
		gnl_content.fd = fd;
		gnl_content.str = ft_strnew(0);
		tmp_lst = ft_lstnew(&gnl_content, sizeof(gnl_content));
		ft_lstadd(&gnl, tmp_lst);
	}
	if ((read_from_fd(&(*(t_file*)(tmp_lst->content))) == -1))
		return (-1);
	return (fill_line(line, &(((t_file *)(tmp_lst->content))->str)));
}
