/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:33:07 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/13 02:27:26 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_separator(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_count_words(char const *s)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ((i > 0 && !ft_separator(s[i]) && ft_separator(s[i - 1])) || \
			(i == 0 && s[0] != ' ' && s[0] != '\t'))
			words++;
		i++;
	}
	return (words);
}

char	**split_texture(char const *s)
{
	int		words;
	char	**strs;

	if (!s)
		return (NULL);
	words = ft_count_words(s);
	if (words < 2)
		exit_msg("Error\nTextures format is not valid\n", 1);
	strs = (char **)malloc(sizeof(char *) * (2 + 1));
	if (!strs)
		return (NULL);
	strs[0] = ft_substr(s, 0, 2);
	strs[1] = ft_substr(s, 2, ft_strlen(s) - 2);
	strs[2] = NULL;
	return (strs);
}

void	check_color_and_texture(char *str, int *arr, t_parse_info *data)
{
	if (ft_strcmp(str, "NO") == 0)
		arr[0]++;
	else if (ft_strcmp(str, "SO") == 0)
		arr[1]++;
	else if (ft_strcmp(str, "WE") == 0)
		arr[2]++;
	else if (ft_strcmp(str, "EA") == 0)
		arr[3]++;
	else if (ft_strcmp(str, "F ") == 0 || \
		ft_strcmp(str, "F\t") == 0)
		arr[4]++;
	else if (ft_strcmp(str, "C ") == 0 || \
		ft_strcmp(str, "C\t") == 0)
		arr[5]++;
}

void	read_and_check_texture(char **line, t_parse_info *data, int fd)
{
	int			i;
	char		*sub_str;
	static int	check_arr[6];

	i = 0;
	ft_bzero(check_arr, sizeof check_arr);
	while (i < 6)
	{
		if (!(*line))
			break ;
		else if (is_whitespace(*line))
		{
			sub_str = ft_substr(ft_strtrim((*line), " \t"), 0, 2);
			check_color_and_texture(sub_str, check_arr, data);
			data->textures[i++] = ft_strdup(ft_strtrim((*line), " \t"));
		}
		free(*line);
		*line = get_next_line(fd);
	}
	data->textures[i] = NULL;
	i = 0;
	while (i < 6)
	{
		if (check_arr[i] != 1)
			exit_msg("Error\nThe textures identifiers are not valid\n", 1);
		i++;
	}
}
