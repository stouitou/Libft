/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:32:20 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/10 15:37:44 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr(int fd, t_print *info, long int nbr)
{
	char		c;
	long int	n;

	n = nbr;
	if (nbr < 0)
		info->length += write(fd, "-", 1);
	if (nbr >= 10)
		putnbr(fd, info, nbr / 10);
	c = nbr % 10 + '0';
	info->length += write(fd, &c, 1);
}

void	print_nbr(int fd, t_print *info, int nbr)
{
	print_prefix(fd, info);
	putnbr(fd, info, nbr);
	print_suffix(fd, info);
	info->flag = 0;
	info->color = 0;
}
