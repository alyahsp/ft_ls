/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:20:24 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/16 22:27:00 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_error(int i, char *str)
{
	errno = 0;
	if (i == 0)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(str[0], 2);
		ft_putendl_fd("\nusage: ls [-lRart] [file ...]", 2);
		exit(1);
	}
	if (i == 1)
		ft_printf("ft_ls: %s: Permission denied\n", str);
	if (i == 2)
	{
		perror(str);
		exit(1);
	}
}

static t_list	*get_flst(char **argv, t_list *files, t_flags *flags)
{
	int		i;
	int		check;
	i = 1;
	while (argv[i])
	{
		if ((argv[i][0] == '-' && argv[i][1] != '-') && check == 0)
			get_flag(argv[i], flags);
		else if (argv[i][0] == '-' && argv[i][1] == '-')
			check = 1;
		else
		{
			files = start_flist(argv[i], flags, files);
			check = 1;
		}
		i++;
	}
	return (files);
}

static t_list	*get_list(char **argv, t_list *lst, int *check, t_flags *flags)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if ((argv[i][0] == '-' && argv[i][1] != '-') && (*check) == 0)
			;
		else if (argv[i][0] == '-' && argv[i][1] == '-')
			(*check) = 1;
		else
		{
			lst = start_list(argv[i], flags, lst);
			(*check) = 1;
		}
		i++;
	}
	return (lst);
}

int		main(int argc, char **argv)
{
	int 	check;
	t_flags	flags;
	t_list	*lst;
	t_list	*files;

	check = 0;
	lst = NULL;
	files = NULL;
	flags = (t_flags) {0, 0, 0, 0, 0, 0, 0};
	files = get_flst(argv, files, &flags);
	lst = get_list(argv, lst, &check, &flags);
	(check == 0) ? lst = start_list(".", &flags, lst) : 0;
	if (files)
		ft_fls(files, &flags);
	if (lst)
		ft_ls(lst, files, &flags);
	return (0);
}
