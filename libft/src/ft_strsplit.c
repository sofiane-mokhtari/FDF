/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:18:04 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/16 15:34:36 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strtrim_char(char *s, char c)
{
	char	*dst;
	int		i;

	i = 0;
	if ((dst = ft_strdup(s)) == NULL)
		return (NULL);
	while (dst[i] && dst[i] == c)
		i++;
	dst = dst + i;
	i = ft_strlen(dst) - 1;
	while (dst[i] && dst[i] == c)
		i--;
	dst[i + 1] = '\0';
	return (dst);
}

static int		ft_count_words(char *str, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	if (ft_strcmp(str, ""))
		words++;
	while (str[i])
	{
		if (str[i + 1] && str[i + 1] == c && str[i] != c)
			words++;
		i++;
	}
	return (words);
}

static int		ft_word_size(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*str;
	int		nb;
	char	**tab;

	if (s == NULL || c == 0 || (str = ft_strtrim_char((char*)s, c)) == NULL)
		return (NULL);
	nb = ft_count_words(str, c);
	tab = (char**)malloc((nb + 1) * sizeof(char*));
	tab[nb] = 0;
	nb = 0;
	while (*str)
		if (*str == c)
			str++;
		else if (*str == 0)
			break ;
		else
		{
			if ((tab[nb] = ft_strnew(ft_word_size(str, c))) == NULL)
				return (NULL);
			ft_strncpy(tab[nb], str, ft_word_size(str, c));
			nb++;
			str = str + ft_word_size(str, c);
		}
	return (tab);
}
