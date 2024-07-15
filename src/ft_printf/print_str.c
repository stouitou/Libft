/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:15:50 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/11 14:06:14 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(int fd, t_print *info, char *str)
{
	info->conversion = 's';
	if (str == NULL)
		str = "(null)";
	print_prefix(fd, info);
	info->length += write(fd, str, ft_strlen(str));
	print_suffix(fd, info);
	reset_info(info);
}
