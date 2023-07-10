/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 03:05:38 by moel-asr          #+#    #+#             */
/*   Updated: 2023/07/10 03:06:38 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	read_and_check_map_util(t_map_info *data)
{
	int	i;

	i = 0;
	while (i < data->map_lines_num)
	{
		if (ft_strlen(data->util_map[i]) > data->width)
			data->width = ft_strlen(data->util_map[i]);
		i++;
	}
	i = 0;
	while (i < data->map_lines_num)
		data->map[i++] = (char *)malloc(sizeof(char) * (data->width + 1));
	data->map[i] = NULL;
	read_map(data);
}

void	read_map(t_map_info *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_lines_num)
	{
		j = 0;
		while (j < data->width)
		{
			if (j < ft_strlen(data->util_map[i]))
				data->map[i][j] = data->util_map[i][j];
			else
				data->map[i][j] = '#';
			j++;
		}
		data->map[i][j] = '\0';
		free(data->util_map[i++]);
	}
	free(data->util_map);
}
