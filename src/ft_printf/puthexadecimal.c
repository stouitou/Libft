/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:58:20 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/11 13:06:06 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	puthexadecimal(int fd, t_print *info, unsigned long nbr, char *base)
{
	char	c;

	if (nbr >= 16)
		puthexadecimal(fd, info, nbr / 16, base);
	c = base[nbr % 16];
	info->length += write(fd, &c, 1);
}
