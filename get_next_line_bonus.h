/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:45:49 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/02 21:25:32 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

char		*get_next_line_bonus(int fd);
size_t		ft_strlen(const char *str);
char		*ft_save(char *str);
char		*check(char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin(char *s1, char *s2);

#endif
