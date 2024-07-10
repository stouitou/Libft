/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:15:50 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/10 15:36:45 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(int fd, t_print *info, char *str)
{
	if (str == NULL)
		str = "(null)";
	print_prefix(fd, info);
	info->length += write(fd, str, ft_strlen(str));
	print_suffix(fd, info);
	info->flag = 0;
	info->color = 0;
}
