/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:32:05 by moel-asr          #+#    #+#             */
/*   Updated: 2023/07/06 17:39:57 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_colors(t_map_info *data)
{
	char	*floor_color;
	char	*ceiling_color;
	int		i;
	int		j;
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
	check_commas_in_rgb_colors(&floor_color, &ceiling_color, data);
}

void	check_commas_in_rgb_colors(char **color_1, char **color_2, \
		t_map_info *data)
{
	int	i;
	int	commas;

	i = 0;
	commas = 0;
	while ((*color_1)[i] || (*color_2)[i])
	{
		if ((*color_1)[i] && (*color_1)[i] == ',')
			commas++;
		if ((*color_2)[i] && (*color_2)[i] == ',')
			commas++;
		i++;
	}
	if (commas != 4)
		exit_msg("Error\nRGB color format is not valid\n", 1);
	data->floor_rgb = ft_split(*color_1, ',');
	data->ceiling_rgb = ft_split(*color_2, ',');
	free(*color_1);
	free(*color_2);
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
