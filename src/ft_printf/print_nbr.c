/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:32:20 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/12 14:12:46 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr(int fd, t_print *info, long int nbr)
{
	char		c;

	if (nbr < 0)
	{
		info->length += write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		putnbr(fd, info, nbr / 10);
	c = nbr % 10 + '0';
	info->length += write(fd, &c, 1);
}

static void	print_spaces_and_plus(int fd, t_print *info, long int nbr)
{
	int	len;
	int	diff;

	if (!info->plus && !info->space)
		return ;
	if (nbr < 0 || !info->plus)
		len = ft_nbrlen(nbr);
	else
		len = ft_nbrlen(nbr) + 1;
	diff = info->width - len;
	while (diff > 0)
	{
		info->length += write(fd, " ", 1);
		diff--;
	}
	if (nbr >= 0 && info->plus)
		info->length += write(fd, "+", 1);
}

void	print_nbr(int fd, t_print *info, int nbr)
{
	info->conversion = 'd';
	print_prefix(fd, info);
	print_spaces_and_plus(fd, info, nbr);
	putnbr(fd, info, nbr);
	print_suffix(fd, info);
	reset_info(info);
}
