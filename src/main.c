/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:20:24 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/11 18:24:00 by spalmaro         ###   ########.fr       */
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
		ft_printf("ft_ls: %s: Permission denied\n", str);
	if (i == 2)
	{
		// perror(i);
		exit(1);
	}
	exit(1);
}

int		main(int argc, char **argv)
{
	int		i;
	int 	check;
	t_list	*lst;
	t_flags	flags;

	i = 1;
	check = 0;
	lst = NULL;
	flags = (t_flags) {0, 0, 0, 0, 0, 0, 0};
	while (argv[i])
	{
		if ((argv[i][0] == '-' && argv[i][1] != '-') && check == 0)
			get_flag(argv[i], &flags);
		else if (argv[i][0] == '-' && argv[i][1] == '-')
			check = 1;
		else
		{
			lst = start_list(argv[i], &flags, lst);
			check = 1;
		}
		i++;
	}
	ft_ls(lst, &flags);
	return (0);
}
