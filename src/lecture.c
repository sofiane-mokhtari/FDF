/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 20:13:21 by smokhtar          #+#    #+#             */
/*   Updated: 2017/12/11 15:36:32 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_readd(int fd)
{
	char	**line;
	char	*str;
	char	*g;
	int		a;

	a = 1;
	if (!(g = (char*)malloc(sizeof(char) * 3)))
		return (NULL);
	g = " \n\0";
	if (!(line = (char**)malloc(2 * sizeof(char*))))
		return (NULL);
	line[1] = 0;
	if (!(str = ft_strnew(1)))
		return (NULL);
	while (get_next_line(fd, line) > 0)
	{
		str = ft_strjoin(str, line[0]);
		str = ft_strjoin(str, g);
	}
	line[0] = str;
	line = ft_strsplit(line[0], '\n');
	return (line);
}

int		**ft_file(int fd, void *param, int i, int a)
{
	int		**tab;
	char	**str;
	char	**buff;
	t_ptr	*ptr;

	ptr = param;
	if (!(str = ft_readd(fd)))
		return (NULL);
	ptr->tab_x = ft_tablen(str);
	tab = (int**)malloc(sizeof(int*) * ft_tablen(str));
	while (i < ft_tablen(str))
	{
		buff = ft_strsplit(str[i], ' ');
		ptr->tab_y = ft_tablen(buff);
		if (!(tab[i] = (int*)malloc(sizeof(int) * ft_tablen(buff))))
			return (NULL);
		while (buff[a])
		{
			tab[i][a] = ft_atoi(buff[a]);
			a++;
		}
		a = 0;
		i++;
	}
	return (tab);
}

int		ft_part1(char *file, void *param)
{
	int		fd;
	t_ptr	*ptr;
	int		i;
	int		a;

	i = 0;
	a = 0;
	ptr = param;
	if ((fd = open(file, O_RDONLY)) == 0)
		return (0);
	ptr->tab = ft_file(fd, param, i, a);
	close(fd);
	return (1);
}
