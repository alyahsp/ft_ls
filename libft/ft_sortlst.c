/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:21:29 by spalmaro          #+#    #+#             */
/*   Updated: 2017/03/11 17:50:53 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_sortlst(t_list *lst, int (*cmp)(void*, void*))
{
	t_list	*cur1;
	t_list	*cur2;
	t_list	tmp;

	cur1 = lst;
	while (cur1)
	{
		cur2 = cur1->next;
		while (cur2)
		{
			if (cmp(cur1->content, cur2->content) == 0)
			{
				tmp.content = cur2->content;
				cur2->content = cur1->content;
				cur1->content = tmp.content;
			}
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
	return (lst);
}
