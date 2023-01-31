/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:41:50 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/02 21:26:26 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	int		a;
	int		res;
	char	*cpy;

	a = 0;
	res = ft_strlen(s1) + 1;
	cpy = (char *)malloc(res * sizeof(char));
	if (!cpy)
		return (0);
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
	static char	*save[12000];
	t_nvr		x;

	if (!save[fd])
		save[fd] = ft_strdup("");
	x.s2 = save[fd];
	x.a = 1;
	while (x.a > 0)
	{
		x.buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
		x.a = read(fd, x.buff, BUFFER_SIZE);
		if (x.a >= 0)
			x.buff[x.a] = 0;
		if (x.a < 0 || (!x.buff[0] && ! x.s2[0]))
			return (free(save[fd]), free(x.buff), save[fd] = NULL, NULL);
		x.hold = x.s2;
		x.s2 = ft_strjoin(x.s2, x.buff);
		if (!(x.s2))
			return (NULL);
		ft_free(x.hold, x.buff);
		x.s1 = check(x.s2);
		if (x.s1 != 0)
			return (save[fd] = ft_save(x.s2), free(x.s2), x.s1);
	}
	return (free(x.s1), save[fd] = NULL, x.s2);
}
int main()
{
	int fd = open("file", O_RDONLY);
	int fd1 = open("file1", O_RDONLY);
	int fd2 = open("file2", O_RDONLY);
	int fd3 = open("file3", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));
	// printf("%s", get_next_line(fd))
}