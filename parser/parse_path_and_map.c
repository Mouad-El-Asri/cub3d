/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path_and_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:06:44 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/19 17:17:56 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_path_errors(t_map_info *data)
{
	int		i;
	int		j;
	int		fd;
	char	**extensions;

	if (data->args != 2)
		exit_msg("Error\nThe number of arguments is invalid !!!\n", 1);
	fd = open(data->map_path, O_RDONLY);
	if (!ft_strstr(data->map_path, ".cub"))
		exit_msg("Error\nThe file's extension is not correct\n", 1);
	extensions = ft_split(ft_strstr(data->map_path, ".cub"), '.');
	i = 0;
	while (extensions[i])
	{
		if (ft_strcmp(extensions[i], "cub"))
			exit_msg("Error\nThe file's extension is not correct\n", 1);
		i++;
	}
	j = 0;
	while (extensions[j])
		free(extensions[j++]);
	free(extensions);
	if (fd < 0)
		exit_msg("Error\nThe file doesn't exist !!!\n", 1);
	close(fd);
}

void	check_map_and_texture_errors(t_map_info *data)
{
	int		fd;
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	data->textures = (char **)malloc(sizeof(char *) * (6 + 1));
	if (!data->textures)
		exit_msg("Error\nMemory allocation failed.\n", 1);
	count_map_lines(data);
	if (data->map_lines_num == -6)
		exit_msg("Error\nThe map is empty\n", 1);
	line = get_next_line(fd);
	read_and_check_texture(&line, data, fd);
	check_colors(data);
	check_rgb_colors_format(data);
	assign_texture_paths(data);
	if (data->map_lines_num == 0)
		exit_msg("Error\nThere is no map to render\n", 1);
	data->map = (char **)malloc(sizeof(char *) * (data->map_lines_num + 1));
	if (!data->map)
		exit_msg("Error\nMemory allocation failed.\n", 1);
	read_and_check_map(&line, data, fd);
	check_map_characters(data);
	check_map_walls(data);
	close(fd);
}
