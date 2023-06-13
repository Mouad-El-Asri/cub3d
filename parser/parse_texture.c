/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:33:07 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/13 20:10:12 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	read_and_check_texture(char **line, t_map_info *data, int fd)
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

void	check_color_and_texture(char *str, int *arr, t_map_info *data)
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

void	assign_texture_paths(t_map_info *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->textures[i][0] == 'N')
			data->texture_data.north_path = ft_strtrim(\
			split_texture(data->textures[i])[1], " \t");
		else if (data->textures[i][0] == 'S')
			data->texture_data.south_path = ft_strtrim(\
			split_texture(data->textures[i])[1], " \t");
		else if (data->textures[i][0] == 'W')
			data->texture_data.west_path = ft_strtrim(\
			split_texture(data->textures[i])[1], " \t");
		else if (data->textures[i][0] == 'E')
			data->texture_data.east_path = ft_strtrim(\
			split_texture(data->textures[i])[1], " \t");
		i++;
	}
}
