/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_and_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:06:44 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/10 20:13:25 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_check_path_errors(t_pars *var)
{
	int	fd;

	if (var->args != 2)
		exit_msg("Error\nThe number of arguments is invalid !!!\n", 1);
	fd = open(var->map_path, O_RDONLY);
	if (!(ft_strstr(var->map_path, ".cub")) \
		|| ft_strcmp(ft_strstr(var->map_path, ".cub"), ".cub"))
		exit_msg("Error\nThe file's extension is not correct\n", 1);
	else if (fd < 0)
		exit_msg("Error\nThe file doesn't exist !!!\n", 1);
	close(fd);
}

void	ft_check_map_and_textures_errors(t_pars *var)
{
	ft_read_textures_and_map(var);
}
