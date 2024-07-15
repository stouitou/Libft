/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_up_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:00:34 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/11 14:07:41 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_up_hexadecimal(int fd, t_print *info, unsigned long nbr)
{
	info->conversion = 'X';
	print_prefix(fd, info);
	puthexadecimal(fd, info, nbr, UP_HEXABASE);
	print_suffix(fd, info);
	reset_info(info);
}
