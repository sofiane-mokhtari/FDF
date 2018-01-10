/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:52:10 by smokhtar          #+#    #+#             */
/*   Updated: 2017/12/16 16:15:35 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_create_win(void *param, int x, int y, char *title)
{
	t_ptr	*ptr;

	ptr = param;
	ptr->win = mlx_new_window(ptr->mlx, x, y, title);
	return (0);
}

int		ft_key(int keycode, void *param)
{
	t_ptr	*ptr;

	ptr = param;
	if (keycode == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit(0);
	}
	return (0);
}

int		ft_init(void *param)
{
	t_ptr *ptr;

	ptr = param;
	ptr->mlx = mlx_init();
	ft_create_win(param, XX, YY, "test");
	ft_print_point(ft_find_start(param));
	mlx_key_hook(ptr->win, ft_key, param);
	mlx_loop(ptr->mlx);
	return (1);
}