/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:32:05 by moel-asr          #+#    #+#             */
/*   Updated: 2023/07/03 02:49:50 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_colors(t_map_info *data)
{
	char	*floor_color;
	char	*ceiling_color;
	int		i;
	int		j;
	int		commas;
	char	**color_parts;

	i = 0;
	while (i < 6)
	{
		color_parts = split_texture(data->textures[i]);
		if (data->textures[i][0] == 'F')
			floor_color = ft_strtrim(color_parts[1], " \t");
		else if (data->textures[i][0] == 'C')
			ceiling_color = ft_strtrim(color_parts[1], " \t");
		j = 0;
		while (color_parts[j])
			free(color_parts[j++]);
		free(color_parts);
		i++;
	}
	if (ft_strchr(floor_color, ' ') || ft_strchr(floor_color, '\t'))
		exit_msg("Error\nFloor RGB color format is not valid\n", 1);
	if (ft_strchr(ceiling_color, ' ') || ft_strchr(ceiling_color, '\t'))
		exit_msg("Error\nCeiling RGB color format is not valid\n", 1);
	i = 0;
	commas = 0;
	while (floor_color[i] || ceiling_color[i])
	{
		if (floor_color[i] && floor_color[i] == ',')
			commas++;
		if (ceiling_color[i] && ceiling_color[i] == ',')
			commas++;
		i++;
	}
	if (commas != 4)
		exit_msg("Error\nRGB color format is not valid\n", 1);
	data->floor_rgb = ft_split(floor_color, ',');
	data->ceiling_rgb = ft_split(ceiling_color, ',');
	free(floor_color);
	free(ceiling_color);
}

void	check_rgb_colors_format(t_map_info *data)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (data->floor_rgb[i++])
		count++;
	if (count != 3)
		exit_msg("Error\nFloor RGB color format is not valid\n", 1);
	data->texture_data.fr = ft_cub_atoi(data->floor_rgb[0]);
	data->texture_data.fg = ft_cub_atoi(data->floor_rgb[1]);
	data->texture_data.fb = ft_cub_atoi(data->floor_rgb[2]);
	count = 0;
	i = 0;
	while (data->ceiling_rgb[i++])
		count++;
	if (count != 3)
		exit_msg("Error\nCeiling RGB color format is not valid\n", 1);
	data->texture_data.cr = ft_cub_atoi(data->ceiling_rgb[0]);
	data->texture_data.cg = ft_cub_atoi(data->ceiling_rgb[1]);
	data->texture_data.cb = ft_cub_atoi(data->ceiling_rgb[2]);
}
