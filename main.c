/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:00:24 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/09 23:30:51 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_map_info	data;

	data.args = argc;
	data.map_path = argv[1];
	check_path_errors(&data);
	check_map_and_texture_errors(&data);
	get_textures_path(&data);
	rey_casting(&data);
}
