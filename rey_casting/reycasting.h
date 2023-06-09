/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:28:36 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/09 15:30:26 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REYCASTING_H
# define REYCASTING_H

# include "../cub3d.h"

# define BLOCK_SIZE 48

# define WIDTH 800
# define HEIGHT 600

# define RIGHT 124
# define LEFT 123
# define DOWN 125
# define UP 126
# define ESC 53

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	char			**map;
	int				width;
	int				height;	

}				t_data;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	free_list(char **list);
void	exit_msg(char *msg, int status);
int		exit_program(int key_code);
int		exit_esc(int key_code);

#endif