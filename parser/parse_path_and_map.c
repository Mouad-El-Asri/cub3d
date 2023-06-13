/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path_and_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:06:44 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/13 02:38:00 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_path_errors(t_parse_info *data)
{
	int	fd;

	if (data->args != 2)
		exit_msg("Error\nThe number of arguments is invalid !!!\n", 1);
	fd = open(data->map_path, O_RDONLY);
	if (!(ft_strstr(data->map_path, ".cub")) || \
		ft_strcmp(ft_strstr(data->map_path, ".cub"), ".cub"))
		exit_msg("Error\nThe file's extension is not correct\n", 1);
	else if (fd < 0)
		exit_msg("Error\nThe file doesn't exist !!!\n", 1);
	close(fd);
}

void	check_map_and_texture_errors(t_parse_info *data)
{
	int		fd;
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	data->textures = (char **)malloc(sizeof(char *) * (6 + 1));
	count_map_lines(data);
	data->map = (char **)malloc(sizeof(char *) * (data->map_lines_num));
	line = get_next_line(fd);
	read_and_check_texture(&line, data, fd);
	check_colors(data);
	check_rgb_colors_format(data);
	read_and_check_map(&line, data, fd);
	check_map_characters(data);
	check_map_walls(data);
	close(fd);
}
