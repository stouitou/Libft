/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:17:55 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/11 14:06:31 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(int fd, t_print *info, void *ptr)
{
	info->conversion = 'p';
	if (ptr == NULL)
	{
		print_str(fd, info, "(nil)");
		return ;
	}
	print_prefix(fd, info);
	info->length += write(fd, "0x", 2);
	puthexadecimal(fd, info, (unsigned long)ptr, LOW_HEXABASE);
	print_suffix(fd, info);
	reset_info(info);
}
