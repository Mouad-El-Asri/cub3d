/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:05:03 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/10 20:30:54 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

void	ft_map_lines_count(t_pars *var)
{
	int		fd;
	char	*line;
	size_t	lenght;

	fd = open(var->map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit_msg("Error\nThe map is empty\n", 1);
	var->map_lines_count = -6;
	if (is_whitespace(line) == 1)
		var->map_lines_count++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && is_whitespace(line) == 1)
			var->map_lines_count++;
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

void	ft_check_textures(char *line, t_pars *var, int fd)
{
	int			i;
	char		*sub_str;
	static int	check_arr[6];

	i = 0;
	ft_bzero(check_arr, sizeof check_arr);
	while (i < 6)
	{
		if (!line)
			break ;
		else if (is_whitespace(line))
		{
			sub_str = ft_substr(ft_strtrim(line, " \t"), 0, 2);
			check_color_and_start_position(sub_str, check_arr, var);
			var->textures[i++] = ft_strdup(ft_strtrim(line, " \t"));
		}
		free(line);
		line = get_next_line(fd);
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

// void	ft_check_map(char *line, t_pars *var, int fd)
// {
	
// }

void	ft_read_textures_and_map(t_pars *var)
{
	int		fd;
	char	*line;

	fd = open(var->map_path, O_RDONLY);
	var->textures = (char **)malloc(sizeof(char *) * (6 + 1));
	var->map = (char **)malloc(sizeof(char *) * (var->map_lines_count));
	line = get_next_line(fd);
	ft_check_textures(line, var, fd);
	close(fd);
}
