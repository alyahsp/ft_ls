/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:10:51 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/11 16:11:26 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void        ft_print_tab(int **tab, int y, int x)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < y)
    {
        while (j < x)
        {
            ft_printf("%d ", tab[i][j]);
            j++;
        }
        j = 0;
        ft_putstr("\n");
        i++;
    }
}
