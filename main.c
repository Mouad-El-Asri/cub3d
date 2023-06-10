/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:00:24 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/10 23:20:18 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parser/parser.h"

int	main(int argc, char **argv)
{
	t_pars	var;

	var.args = argc;
	var.map_path = argv[1];
	ft_check_path_errors(&var);
	ft_check_map_and_textures_errors(&var);
}
