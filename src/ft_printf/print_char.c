/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:12:29 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/11 14:05:59 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int fd, t_print *info, int c)
{
	info->conversion = 'c';
	print_prefix(fd, info);
	info->length += write(fd, &c, 1);
	print_suffix(fd, info);
	reset_info(info);
}
