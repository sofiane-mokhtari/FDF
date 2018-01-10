/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubletab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:36:34 by smokhtar          #+#    #+#             */
/*   Updated: 2017/12/11 15:39:10 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_doubletab(int **tab, int x, int y)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (e < x)
	{
		while (i < y)
		{
			ft_putnbr(tab[e][i]);
			i++;
		}
		ft_putchar('\n');
		i = 0;
		e++;
	}
}
