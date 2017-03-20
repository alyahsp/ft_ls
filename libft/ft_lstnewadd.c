/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:30:17 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/20 13:30:20 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnewadd(t_list *lst, t_list *dlst)
{
	t_list *tmp;

	if (!(tmp = ft_lstnew(dlst, sizeof(t_list))))
		return (NULL);
	if (!lst)
		lst = tmp;
	else
		ft_lstaddend(&lst, tmp);
	return (lst);
}
