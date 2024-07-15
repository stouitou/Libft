/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:37:55 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/11 14:05:25 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prefix(int fd, t_print *info)
{
	if (info->hash)
	{
		if (info->conversion == 'x')
			info->length += write(fd, "0x", 2);
		if (info->conversion == 'X')
			info->length += write(fd, "0X", 2);
	}
	if (info->quest)
	{
		write(fd, "\033[1;", 7);
		ft_putnbr_fd(info->color, fd);
		write(fd, "m", 1);
	}
}
