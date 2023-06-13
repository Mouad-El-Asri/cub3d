/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:05:03 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/13 01:19:01 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
			i++;
		else
			return (1);
	}
	return (0);
}

void	count_map_lines(t_pars *var)
{
	int		fd;
	char	*line;
	size_t	lenght;

	fd = open(var->map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit_msg("Error\nThe map is empty\n", 1);
	var->map_lines_num = -6;
	if (is_whitespace(line) == 1)
		var->map_lines_num++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && is_whitespace(line) == 1)
			var->map_lines_num++;
	}
	close(fd);
}

void	check_color_and_start_position(char *str, int *arr, t_pars *var)
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

void	read_and_check_textures(char **line, t_pars *var, int fd)
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
			check_color_and_start_position(sub_str, check_arr, var);
			var->textures[i++] = ft_strdup(ft_strtrim((*line), " \t"));
		}
		free(*line);
		*line = get_next_line(fd);
	}
	var->textures[i] = NULL;
	i = 0;
	while (i < 6)
	{
		if (check_arr[i] != 1)
			exit_msg("Error\nThe textures identifiers, "
				"files or colors are invalid\n", 1);
		i++;
	}
}

void	check_textures_colors(t_pars *var)
{
	char	*floor_color;
	char	*ceiling_color;
	int		i;

	i = 0;
	while (i < 6)
	{
		if (var->textures[i][0] == 'F')
			floor_color = ft_strtrim(split_textures(var->textures[i])[1], " \t");
		else if (var->textures[i][0] == 'C')
			ceiling_color = ft_strtrim(split_textures(var->textures[i])[1], \
			" \t");
		i++;
	}
	if (ft_strchr(floor_color, ' ') || ft_strchr(floor_color, '\t'))
		exit_msg("Error\nFloor RGB color format is not valid\n", 1);
	if (ft_strchr(ceiling_color, ' ') || ft_strchr(ceiling_color, '\t'))
		exit_msg("Error\nCeiling RGB color format is not valid\n", 1);
	var->floor_rgb = ft_split(floor_color, ',');
	var->ceiling_rgb = ft_split(ceiling_color, ',');
}

void	check_rgb_colors_format(t_pars *var)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (var->floor_rgb[i++])
		count++;
	if (count != 3)
		exit_msg("Error\nFloor RGB color format is not valid\n", 1);
	var->fr = ft_cub_atoi(var->floor_rgb[0]);
	var->fg = ft_cub_atoi(var->floor_rgb[1]);
	var->fb = ft_cub_atoi(var->floor_rgb[2]);
	count = 0;
	i = 0;
	while (var->ceiling_rgb[i++])
		count++;
	if (count != 3)
		exit_msg("Error\nCeiling RGB color format is not valid\n", 1);
	var->cr = ft_cub_atoi(var->ceiling_rgb[0]);
	var->cg = ft_cub_atoi(var->ceiling_rgb[1]);
	var->cb = ft_cub_atoi(var->ceiling_rgb[2]);
}

void	read_and_check_map(char **line, t_pars *var, int fd)
{
	int	i;

	i = 0;
	var->width = 0;
	while (is_whitespace(*line) == 0)
		*line = get_next_line(fd);
	while (i < var->map_lines_num)
	{
		var->map[i++] = str_space_trim(ft_strdup(*line));
		free(*line);
		*line = get_next_line(fd);
		if (i < var->map_lines_num && is_whitespace(*line) == 0)
			exit_msg("Error\nUnexpected whitespace found in the map\n", 1);
		if (ft_strlen(var->map[i - 1]) > var->width)
			var->width = ft_strlen(var->map[i - 1]);
	}
	var->map[i] = NULL;
}

char	*str_space_trim(char *s)
{
	int		back;
	char	*str;

	if (!s)
		return (NULL);
	back = ft_strlen(s) - 1;
	while (back && ft_strchr(" ", s[back]))
		back--;
	str = ft_substr(s, 0, back + 1);
	return (str);
}

int	is_valid_character(char c)
{
	if (c != '1' && c != '0' && c != 'N' && \
		c != 'S' && c != 'E' && c != 'W')
		return (1);
	return (0);
}

void	check_map_walls(t_pars *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->map_lines_num)
	{
		j = 0;
		while (j < ft_strlen(var->map[i]))
		{
			if (var->map[i][j] == '\t')
				exit_msg("Error\nUnexpected tab found in the map\n", 1);
			if (var->map[i][j] == '0')
			{
				if ((j == 0) || (j == (ft_strlen(var->map[i]) - 1)) || \
					(i == 0) || (i == (var->map_lines_num - 1)) || \
					(is_valid_character(var->map[i][j - 1])) || \
					(is_valid_character(var->map[i][j + 1])) || \
					(is_valid_character(var->map[i - 1][j])) || \
					(is_valid_character(var->map[i + 1][j])))
					exit_msg("Error\nThe map is not closed\n", 1);
			}
			j++;
		}
		i++;
	}
}

int	is_valid_player_position(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (1);
}

void	check_map_characters(t_pars *var)
{
	int	i;
	int	j;
	int	player_start_position;

	i = 0;
	player_start_position = 0;
	while (i < var->map_lines_num)
	{
		j = 0;
		while (j < ft_strlen(var->map[i]))
		{
			if (is_valid_character(var->map[i][j]) && var->map[i][j] != ' ')
				exit_msg("Error\nUnexpected character found in the map\n", 1);
			else if (is_valid_player_position(var->map[i][j]) == 0)
				player_start_position++;
			j++;
		}
		i++;
	}
	if (!player_start_position)
		exit_msg("Error\nPlayer start position not found\n", 1);
	else if (player_start_position > 1)
		exit_msg("Error\nDuplicate player start position found\n", 1);
}
