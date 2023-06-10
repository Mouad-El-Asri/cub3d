/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:57:18 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/09 18:14:07 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "rey_casting/reycasting.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

# include "minilibft/minilibft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
	int				x;
	int				y;
}				t_map;

void	rey_casting(t_map *map, char *argv);

#endif