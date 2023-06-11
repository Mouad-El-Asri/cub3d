/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:05:03 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/11 23:46:00 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
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
			exit_msg("Error\nThe textures identifiers,"
				"files or colors are invalid\n", 1);
		i++;
	}
}

void	read_and_check_map(char **line, t_pars *var, int fd)
{
	int	i;

	i = 0;
	while (is_whitespace(*line) == 0)
		*line = get_next_line(fd);
	while (i < var->map_lines_num)
	{
		var->map[i++] = ft_strdup(*line);
		free(*line);
		*line = get_next_line(fd);
		if (i < var->map_lines_num && is_whitespace(*line) == 0)
			exit_msg("Error\nUnexpected whitespace found in the map\n", 1);
	}
	var->map[i] = NULL;
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
				if ((j != 0 && is_valid_character(var->map[i][j - 1])) || \
					(j < ft_strlen(var->map[i]) && \
					is_valid_character(var->map[i][j + 1])) || \
					(i != 0 && is_valid_character(var->map[i - 1][j])) || \
					(i < var->map_lines_num && \
					is_valid_character(var->map[i + 1][j])))
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
	int	player_start_postion;

	i = 0;
	player_start_postion = 0;
	while (i < var->map_lines_num)
	{
		j = 0;
		while (j < ft_strlen(var->map[i]))
		{
			if (is_valid_character(var->map[i][j]) && var->map[i][j] != ' ')
				exit_msg("Error\nUnexpected character found in the map\n", 1);
			else if (is_valid_player_position(var->map[i][j]) == 0)
				player_start_postion++;
			j++;
		}
		i++;
	}
	if (!player_start_postion)
		exit_msg("Error\nPlayer start position not found\n", 1);
	else if (player_start_postion > 1)
		exit_msg("Error\nDuplicate player start position found\n", 1);
}

void	count_map_width(t_pars *var)
{
	int	i;
	int	len;

	i = 0;
	var->width = 0;
	while (i < var->map_lines_num)
	{
		len = 0;
		len = ft_strlen(var->map[i]);
		len--;
		while (var->map[i][len] == ' ')
			len--;
		len++;
		if (len > var->width)
			var->width = len;
		i++;
	}
}
