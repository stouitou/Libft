/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_low_hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:26:59 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/10 15:38:25 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_low_hexadecimal(int fd, t_print *info, size_t nbr)
{
	print_prefix(fd, info);
	puthexadecimal(fd, info, nbr, LOW_HEXABASE);
	print_suffix(fd, info);
	info->flag = 0;
	info->color = 0;
}
