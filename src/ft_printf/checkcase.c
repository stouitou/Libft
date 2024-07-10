/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:00:00 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/10 15:38:51 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checkcase(int fd, t_print *info, char c)
{
	if (c == 'c')
		print_char(fd, info, va_arg(info->args, int));
	if (c == 's')
		print_str(fd, info, va_arg(info->args, char *));
	if (c == 'p')
		print_ptr(fd, info, va_arg(info->args, void *));
	if (c == 'd' || c == 'i')
		print_nbr(fd, info, va_arg(info->args, int));
	if (c == 'u')
		print_unsigned(fd, info, va_arg(info->args, size_t));
	if (c == 'x')
		print_low_hexadecimal(fd, info, va_arg(info->args, size_t));
	if (c == 'X')
		print_up_hexadecimal(fd, info, va_arg(info->args, size_t));
	if (c == '%')
		print_char(fd, info, '%');
}
