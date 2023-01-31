/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:45:24 by abelfany          #+#    #+#             */
/*   Updated: 2022/11/05 19:44:47 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char	*ft_save(char *str)
{
	char	*sv;
	int		b;
	int		a;
	int		j;

	a = -1;
	j = 0;
	b = ft_strlen(str) + 1;
	sv = NULL;
	while (str[++a])
	{
		if (str[a] == '\n')
		{
			sv = malloc(b - a);
			if (!sv)
				return (0);
				a++;
			while (a < b)
				sv[j++] = str[a++];
			break ;
		}
	}
	if (*sv)
		sv[j] = '\0';
	return (sv);
}

char	*check(char *str)
{
	char	*sv;
	int		a;
	int		b;

	a = -1;
	sv = NULL;
	b = ft_strlen(str);
	while (++a <= b)
	{
		if (str[a] == '\n')
		{
			b = -1;
			sv = malloc(a + 2);
			if (!sv)
				return (0);
			sv[a + 1] = 0;
			while (++b < a + 1)
				sv[b] = str[b];
			break ;
		}
	}
	if (!sv)
		return (0);
	return (sv);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		a;
	int		x;
	char	*join;

	a = 0;
	if (!s1 && !s2)
		return (0);
	join = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1 * sizeof(char));
	if (!join)
		return (0);
	while (s1[a])
	{
		join[a] = s1[a];
		a++;
	}
	x = 0;
	while (s2[x])
		join[a++] = s2[x++];
	join[a] = '\0';
	return (join);
}
