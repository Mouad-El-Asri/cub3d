/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:59:00 by kmahdi            #+#    #+#             */
/*   Updated: 2023/06/09 13:59:49 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reycasting.h"

void	exit_msg(char *msg, int status)
{
	printf("%s", msg);
	exit(status);
}

void	free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

int	exit_program(int key_code)
{
	exit_msg("Exit the program with the X !!", 0);
	return (0);
}

int	exit_esc(int key_code)
{
	if (key_code == ESC)
		exit_msg("Exit the program with the 'ESC'  button !", 0);
	return (0);
}
