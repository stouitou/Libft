/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:36:12 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/11 14:07:11 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putunsigned(int fd, t_print *info, unsigned int nbr)
{
	char	c;

	if (nbr >= 10)
		putunsigned(fd, info, nbr / 10);
	c = nbr % 10 + '0';
	info->length += write(fd, &c, 1);
}

void	print_unsigned(int fd, t_print *info, unsigned int nbr)
{
	info->conversion = 'u';
	print_prefix(fd, info);
	putunsigned(fd, info, nbr);
	print_suffix(fd, info);
	reset_info(info);
}
