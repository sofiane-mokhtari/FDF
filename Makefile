# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 16:39:33 by smokhtar          #+#    #+#              #
#    Updated: 2018/01/10 16:46:53 by smokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = fdf

flag = -Wall -Werror -Wextra

comp = -lmlx -framework OpenGL -framework AppKit

file =main\
	  lecture\
	  utili\
	  graph\
	  seg\
	  point\

SRC =libft/libft.a\
	 minilibx_macos/libmlx.a\
	 get_next_line/get_next_line.c\

Src = $(addprefix src/, $(file))

src = $(addsuffix .c, $(Src))

object = $(addsuffix .o, $(src))


all: $(name)

$(name) :
	make -C libft/
	make -C minilibx_macos/
	gcc -o $(name) $(comp) $(SRC) $(src) -I. -Ilibft/includes -Iminilibx -Iget_next_line


e : fclean
	make -C libft/
	make -C minilibx_macos/
	gcc -o $(name) $(comp) $(SRC) $(src) -I. -Ilibft/includes -Iminilibx -Iget_next_line
	clear;
	./fdf 42.fdf


f : fclean
	make -C libft/
	make -C minilibx_macos/
	gcc -o $(name) $(comp) $(SRC) $(src) -I. -Ilibft/includes -Iminilibx -Iget_next_line
	./fdf 42.fdf

clean :
	rm -f *.o
	make clean -C libft/

fclean: clean
	rm fdf
	make fclean -C libft/

re : fclean all
