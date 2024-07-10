/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:37:55 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/10 15:35:58 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prefix(int fd, t_print *info)
{
	if (info->flag == COLOR)
	{
		write(fd, "\033[1;", 7);
		ft_putnbr_fd(info->color, fd);
		write(fd, "m", 1);
	}
}
