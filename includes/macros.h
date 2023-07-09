/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 03:26:11 by kmahdi            #+#    #+#             */
/*   Updated: 2023/07/09 00:42:57 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// window_size  --------------------------->

# define WIDTH 1800
# define HEIGHT 1000

// mouse buttons ---------------------------->

# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// objects size ---------------------------->
# define TILE_SIZE 64
# define M_TILE_SIZE 16
# define PLAYER_SIZE 8

// keys codes  ------------------------------>

# define ESC 53
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define DOWN_ARROW 125
# define UP_ARROW 126
# define S_DOWN 1
# define W_UP 13
# define A_LEFT 0
# define D_RIGHT 2

// player movement --------------------------->
# define MOVE_SPEED 15
# define ROTATION_SPEED 0.05

// press ; release code ----------------------->

# define ON_KEYDOWN 2
# define ON_KEYUP 3

#endif