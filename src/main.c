/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:20:24 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/26 17:47:39 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_error(int i)
{
	// i == 1 ? ft_putendl_fd("Error", 2) : 0;
	exit(1);
}

int		main(int argc, char **argv)
{
	int	i;
	int check;

	i = 0;
	check = 0;
	if (argc == 1)
	{

	}
	else
	{
		while (argv[i])
		{
			if (argv[i][0] == '-' && check == 0)
				get_flag(argv[i]);
			else
			{
				start_list(argv[i]);
				cheeck = 1;
			}
		}
	}
	return (0);
}
