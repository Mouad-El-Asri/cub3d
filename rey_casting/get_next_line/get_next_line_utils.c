/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:04:43 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/09 15:31:30 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../reycasting.h"
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*j;

	j = (char *)s;
	i = 0;
	while (j[i])
	{
		if (j[i] == (char)c)
		{
			return (j + i);
		}
		i++;
	}
	if ((char) c == '\0')
		return (j + i);
	return (0);
}

int	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*j;

	if (!s1)
		s1 = calloc(1, 1);
	if (!s2 || s2[0] == 0)
		return (s1);
	i = 0;
	j = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!j)
		return (NULL);
	while (s1[i])
	{
		j[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		j[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	j[ft_strlen(s1) + i] = '\0';
	free(s1);
	return (j);
}
