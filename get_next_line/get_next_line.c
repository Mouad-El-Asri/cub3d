/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:26:01 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/09 18:16:21 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibft/minilibft.h"
#include "get_next_line.h"

char	*ft_free(char *s1, char *s2)
{
	free(s2);
	return (s1);
}

char	*ft_read(int fd, char *result)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	i = 1;
	while (i > 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == (-1))
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		result = ft_free(ft_strjoin(result, str), result);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(str);
	return (result);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_next_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(str) - i));
	i++;
	while (str[i] != '\0')
	{
		line[j] = str[i];
		i++;
		j++;
	}
	line[j] = '\0';
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_get_next_line(str);
	return (line);
}
