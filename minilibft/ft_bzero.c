/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 09:40:54 by moel-asr          #+#    #+#             */
/*   Updated: 2023/06/10 18:52:30 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
