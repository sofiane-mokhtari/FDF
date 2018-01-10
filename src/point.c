/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:02:38 by smokhtar          #+#    #+#             */
/*   Updated: 2018/01/10 19:02:40 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_find_start(void *param)
{
	t_ptr	*ptr;

	ptr = param;
	ptr->y_start = T;
	ptr->x_start = T * ptr->tab_y + 2 * T;
	return (param);
}


int		ft_print_point(void *param)
{
	t_ptr	*ptr;
	int		x;
	int		y;

	ptr = param;
	x = 0;
	y = 0;
	while (x + 1 < ptr->tab_x)
	{
		while (y + 1 < ptr->tab_y)
		{
			ft_point(ptr, x , y);
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

int		ft_point(t_ptr *ptr, int x, int y)
{
	t_dr	dr;

	dr.xa = (ptr->tab_x * T) + (x * T);
	dr.ya = T + (y * T) + ptr->tab[x][y];
	if (x + 1 < ptr->tab_x)
	{
		dr.xb = (ptr->tab_x * T) + ((x + 1) * T);
		dr.yb = T + (y * T) + ptr->tab[x][y];
		ft_put_seg(ptr, dr, R);
	}
	if (y + 1 < ptr->tab_y)
	{
		dr.xb = (ptr->tab_x * T) + (x * T);
		dr.yb = T + ((y + 1) * T) + ptr->tab[x][y];
		ft_put_seg(ptr, dr, R);
	}
	return (1);
}