/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:20:24 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/19 21:48:09 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_error(int i, char *str)
{
	if (i == 0)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(str[0], 2);
		ft_putendl_fd("\nusage: ls [-lRart] [file ...]", 2);
		exit(1);
	}
	if (i == 1)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	else
	{
		ft_putendl_fd(strerror(errno), 2);
		exit(1);
	}
}

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

int		main(int argc, char **argv)
{
	int 	check;
	t_flags	flags;
	t_list	*lst;
	t_list	*fls;

	check = 0;
	lst = NULL;
	fls = NULL;
	flags = (t_flags) {0, 0, 0, 0, 0, 0};
	fls = get_flst(argv, fls, &flags);
	lst = get_list(argv, lst, &check, &flags);
	if (check == 0)
		lst = ft_lstnew(start_list(".", &flags, lst), sizeof(t_data));
	(fls) ? ft_fls(fls, &flags) : 0;
	(lst) ? ft_ls(lst, fls, &flags) : 0;
	return (0);
}
