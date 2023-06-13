/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:32:05 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/13 02:37:07 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_colors(t_parse_info *data)
{
	char	*floor_color;
	char	*ceiling_color;
	int		i;

	i = 0;
	while (i < 6)
	{
		if (data->textures[i][0] == 'F')
			floor_color = ft_strtrim(split_texture(data->textures[i])[1], " \t");
		else if (data->textures[i][0] == 'C')
			ceiling_color = ft_strtrim(split_texture(data->textures[i])[1], \
			" \t");
		i++;
	}
	if (ft_strchr(floor_color, ' ') || ft_strchr(floor_color, '\t'))
		exit_msg("Error\nFloor RGB color format is not valid\n", 1);
	if (ft_strchr(ceiling_color, ' ') || ft_strchr(ceiling_color, '\t'))
		exit_msg("Error\nCeiling RGB color format is not valid\n", 1);
	data->floor_rgb = ft_split(floor_color, ',');
	data->ceiling_rgb = ft_split(ceiling_color, ',');
}

void	check_rgb_colors_format(t_parse_info *data)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (data->floor_rgb[i++])
		count++;
	if (count != 3)
		exit_msg("Error\nFloor RGB color format is not valid\n", 1);
	data->fr = ft_cub_atoi(data->floor_rgb[0]);
	data->fg = ft_cub_atoi(data->floor_rgb[1]);
	data->fb = ft_cub_atoi(data->floor_rgb[2]);
	count = 0;
	i = 0;
	while (data->ceiling_rgb[i++])
		count++;
	if (count != 3)
		exit_msg("Error\nCeiling RGB color format is not valid\n", 1);
	data->cr = ft_cub_atoi(data->ceiling_rgb[0]);
	data->cg = ft_cub_atoi(data->ceiling_rgb[1]);
	data->cb = ft_cub_atoi(data->ceiling_rgb[2]);
}
