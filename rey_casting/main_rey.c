/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:26:27 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/09 15:41:00 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	read_map(t_data *data, char *s)
{
	int	fd;
	int	index;

	index = 0;
	fd = open(s, O_RDONLY);
	while (1)
	{
		data->map[index] = get_next_line(fd);
		if (data->map[index] == NULL)
			break ;
		printf("%s", data->map[index]);
		index++;
	}
	close(fd);
}

t_data	*init_data(t_data *data, char *s)
{
	char	*line;
	int		fd;

	data = malloc(sizeof(t_data));
	data->height = 0;
	data->width = 0;
	fd = open(s, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (data->height == 0 && line == NULL)
			exit_msg("ERROR : \n map !! \n", 1);
		if (line == NULL)
			break ;
		data->width = ft_strlen(line);
		data->height++;
		free(line);
	}
	data->map = malloc((data->height + 1) * sizeof(char *));
	read_map(data, s);
	close(fd);
	return (data);
}

void	rey_casting(t_map *map, char *argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data = init_data(data, argv);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "The_KM_game!");
	mlx_hook(data->mlx_win, 2, 0, exit_esc, data);
	mlx_hook(data->mlx_win, 17, 0, exit_program, data);
	mlx_loop(data->mlx);
}
