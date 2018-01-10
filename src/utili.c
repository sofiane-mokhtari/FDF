/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utili.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 20:15:11 by smokhtar          #+#    #+#             */
/*   Updated: 2017/12/11 15:37:36 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_tabclear(char **str)
{
	while (str)
		ft_strclr(*str++);
}

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
