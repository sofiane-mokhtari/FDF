/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:09:23 by smokhtar          #+#    #+#             */
/*   Updated: 2018/01/09 16:04:55 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int         ft_draw_seg(void *param, t_dr dr)
{
	double  x;
	double  y;
	t_ptr   *ptr;

	ptr = param;
	x = dr.xa;
	y = dr.ya;
	if (dr.xa == dr.xb)
	{
		while (y < dr.yb)
		{
			y = y + 0.2;
			mlx_pixel_put(ptr->mlx, ptr->win, y, x, dr.color);
		}
		return (0);
	}
	while (((y <= dr.yb && dr.coef >= 0) || (y >= dr.yb && dr.coef < 0)) && x <= dr.xb)
	{
		y = x * dr.coef + dr.b;
		mlx_pixel_put(ptr->mlx, ptr->win, y, x, dr.color);
		x = x + 0.2;
	}
	return (0);
}

int         ft_put_seg(void *param, t_dr dr, int color)
{
    dr.color = color;
    ft_draw_seg(param, dr);
    return (0);
}

t_dr    ft_cr_stru(double xa, double ya, double xb, double yb)
{
	t_dr dr;

	dr.coef = (double)(yb - ya) / (xb - xa);
	dr.b = (double)yb - (dr.coef * xb);
	if (xa > xb && ya > yb)
		dr = ft_cr_stru(xb, yb, xa, ya);
	else if (xa > xb && dr.coef < 0)
		dr = ft_cr_stru(xb, yb, xa, ya);
	else if (xa > xb && ya == yb)
		dr = ft_cr_stru(xb, ya, xa, yb);
	else if (ya > yb && xa == xb)
		dr = ft_cr_stru(xa, yb, xb, ya);
	else
	{
		dr.xa = xa;
		dr.xb = xb;
		dr.ya = ya;
		dr.yb = yb;
	}
	return (dr);
}