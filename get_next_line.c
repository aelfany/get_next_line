/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:35:39 by abelfany          #+#    #+#             */
/*   Updated: 2022/11/29 19:26:57 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		a;
	int		res;
	char	*cpy;

	a = 0;
	res = ft_strlen(s1) + 1;
	cpy = (char *)malloc(res * sizeof(char));
	if (!cpy)
		return ("a");
	while (s1[a])
	{
		cpy[a] = s1[a];
		a++;
	}
	cpy[a] = '\0';
	return (cpy);
}

void	ft_free(char *hold, char *buff)
{
	free(hold);
	free(buff);
}

char	*get_next_line(int fd)
{
	static char	*save;
	t_nvr		x;

	if (!save)
		save = ft_strdup("");
	x.s2 = save;
	x.a = 1;
	while (x.a > 0)
	{
		x.buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
		x.a = read(fd, x.buff, BUFFER_SIZE);
		if (x.a >= 0)
			x.buff[x.a] = 0;
		if (x.a < 0 || x.buff == NULL || (!x.buff[0] && !(x.s2)[0]))
			return (free(save), free(x.buff), save = NULL, NULL);
		x.hold = x.s2;
		x.s2 = ft_strjoin(x.s2, x.buff);
		if (!(x.s2))
			return (NULL);
		ft_free(x.hold, x.buff);
		x.s1 = check(x.s2);
		if (x.s1 != 0)
			return (save = ft_save(x.s2), free(x.s2), x.s1);
	}
	return (free(x.s1), save = NULL, x.s2);
}
