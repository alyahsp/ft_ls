/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:20:24 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/17 19:08:11 by spalmaro         ###   ########.fr       */
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
		ft_printf("ft_ls: %s: No such file or directory\n", str);
}

static t_list	*get_list(char **argv, t_list *lst, int *check, t_flags *flags)
{
	int			i;
	t_list		*dlst;
	t_list		*tmp;

	i = 1;
	dlst = NULL;
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			(*check) = 1;
		else if ((argv[i][0] != '-') || (*check) == 1)
		{
			(*check) = 1;
			if ((dlst = start_list(argv[i], flags, dlst)))
			{
				if (!(tmp = ft_lstnew(dlst, sizeof(t_list))))
					return (NULL);
				if (!lst)
					lst = tmp;
				else
					ft_lstaddend(&lst, tmp);
				ft_memdel((void **)&dlst);
			}
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
	t_list	*fls;

	check = 0;
	lst = NULL;
	fls = NULL;
	flags = (t_flags) {0, 0, 0, 0, 0, 0, 0};
	fls = get_flst(argv, fls, &flags);
	lst = get_list(argv, lst, &check, &flags);
	if (check == 0)
		lst = ft_lstnew(start_list(".", &flags, lst), sizeof(t_data));
	(fls) ? ft_fls(fls, &flags) : 0;
	(lst) ? ft_ls(lst, fls, &flags) : 0;
	return (0);
}
