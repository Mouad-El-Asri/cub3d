/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:20:03 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/13 01:19:46 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_cub_atoi(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			exit_msg("Error\nUnexpected character found" \
				" in the RGB color format\n", 1);
		i++;
	}
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - 48);
	if (num > 255)
		exit_msg("Error\nRGB color is out of range\n", 1);
	return (num);
}
