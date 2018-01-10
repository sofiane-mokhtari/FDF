/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:41:19 by smokhtar          #+#    #+#             */
/*   Updated: 2018/01/09 16:05:19 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	void		*param;
	t_ptr		ptr;
	t_dr		dr;
	int			i;
	t_ptr		*p;

	i = 0;
	param = &ptr;
	if (ft_part1(av[1], param) == 0)
		return (0);
	ft_init(param);
	return (0);
}
