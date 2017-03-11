/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:05:32 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/09 21:20:56 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		ft_printf("%s\n", ((t_data *)(lst->content))->file_name);
		lst = lst->next;
	}
}
