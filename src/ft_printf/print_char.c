/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:12:29 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/10 15:36:19 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int fd, t_print *info, int c)
{
	print_prefix(fd, info);
	info->length += write(fd, &c, 1);
	print_suffix(fd, info);
	info->flag = 0;
	info->color = 0;
}
