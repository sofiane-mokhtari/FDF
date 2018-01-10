/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:54:00 by jjauzion          #+#    #+#             */
/*   Updated: 2017/12/10 16:42:55 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 32
# define ERROR -1
# define EOFF 0
# define EOL 1

typedef struct	s_file
{
	char			*buff;
	int				fd;
	int				ret;
	int				index;
	struct s_file	*next;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
