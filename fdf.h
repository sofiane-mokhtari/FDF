/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:06:03 by smokhtar          #+#    #+#             */
/*   Updated: 2018/01/09 16:03:34 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <math.h>

# define BC 0xFEFEFE
# define R 0xFE0000
# define B 0x0000FE
# define V 0x00FE00
# define P 0xCC0099
# define Y 0xCCCC00
# define O 0xFF6600

# define XX 2000
# define YY XX
# define T 50

typedef struct	s_droite
{
	double		xa;
	double		ya;
	double		xb;
	double		yb;
	double		coef;
	double		b;
	int			color;
}				t_dr;

typedef	struct	s_ptr
{
	void		*mlx;
	void		*win;
	int			**tab;
	int			tab_x;
	int			tab_y;
	int			x_start;
	int			y_start;
}				t_ptr;

/* main  */


/*  utile */

void		ft_tabclear(char **str);
int			ft_tablen(char **tab);

/* lecture  */

char		**ft_read(int fd);
int			**ft_file(int fd, void *param, int i, int a);
int			ft_part1(char *file, void *param);

/* graph  */

int			ft_key(int keycode, void *param);
int			ft_create_win(void *param, int x, int y, char *title);
int			ft_init(void *param);

/*  seg */


int			ft_put_seg(void *param, t_dr dr, int color);
t_dr    	ft_cr_stru(double xa, double ya, double xb, double yb);
int         ft_draw_seg(void *param, t_dr dr);

/*.  point */

int			ft_print_point(void *param);
int			ft_point(t_ptr *ptr, int x, int y);


#endif
