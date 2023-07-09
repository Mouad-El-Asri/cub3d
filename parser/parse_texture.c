/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:33:07 by moel-asr          #+#    #+#             */
/*   Updated: 2023/07/09 20:51:43 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_color_and_texture(char *str, int *arr)
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

void	read_and_check_texture(char **line, t_map_info *data, int fd)
{
	int			i;
	char		*sub_str;
	char		*trimmed_line;
	static int	check_arr[6];

	i = 0;
	sub_str = NULL;
	trimmed_line = NULL;
	while (i < 6)
	{
		if (!(*line))
			break ;
		else if (is_whitespace(*line))
		{
			trimmed_line = ft_strtrim((*line), " \t");
			sub_str = ft_substr(trimmed_line, 0, 2);
			check_color_and_texture(sub_str, check_arr);
			data->textures[i++] = trimmed_line;
			free(sub_str);
		}
		free(*line);
		*line = get_next_line(fd);
	}
	data->textures[i] = NULL;
	print_texture_error(check_arr);
}

void	print_texture_error(int *arr)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (arr[i] != 1)
			exit_msg("Error\nThe textures identifiers are not valid\n", 1);
		i++;
	}
}

void	assign_texture_paths(t_map_info *data)
{
	int		i;
	int		j;
	char	**texture_parts;

	i = -1;
	texture_parts = NULL;
	while (++i < 6)
	{
		texture_parts = split_texture(data->textures[i]);
		if (data->textures[i][0] == 'N')
			data->texture_data.north_path = ft_strtrim(texture_parts[1], " \t");
		else if (data->textures[i][0] == 'S')
			data->texture_data.south_path = ft_strtrim(texture_parts[1], " \t");
		else if (data->textures[i][0] == 'W')
			data->texture_data.west_path = ft_strtrim(texture_parts[1], " \t");
		else if (data->textures[i][0] == 'E')
			data->texture_data.east_path = ft_strtrim(texture_parts[1], " \t");
		j = 0;
		while (texture_parts[j])
			free(texture_parts[j++]);
		free(texture_parts);
	}
}

void	get_textures_path(t_map_info *data)
{
	int		i;
	int		j;
	int		x;
	char	*n;

	x = 0;
	i = -1;
	data->textures_path = malloc(sizeof(char *) * 4);
	while (data->textures && data->textures[++i])
	{
		j = -1;
		while (data->textures[i][++j])
		{
			if (data->textures[i][j] == '.')
			{
				n = ft_substr(data->textures[i], j,
						ft_strlen(data->textures[i]));
				data->textures_path[x++] = ft_strdup(n);
				free(n);
				break ;
			}
		}
	}
	data->textures_path[x++] = NULL;
	free_list(data->textures);
}
