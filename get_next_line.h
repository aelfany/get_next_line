/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:41:08 by abelfany          #+#    #+#             */
/*   Updated: 2022/11/29 19:26:45 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>

typedef struct s_nvr
{
	char	*buff;
	char	*hold;
	char	*s2;
	char	*s1;
	int		a;
}	t_nvr;

char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_save(char *str);
char		*check(char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin(char *s1, char *s2);

#endif
