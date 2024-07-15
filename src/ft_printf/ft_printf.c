/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:36:25 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/12 14:12:42 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initialize_info(t_print *info)
{
	info->conversion = 0;
	info->hash = 0;
	info->plus = 0;
	info->space = 0;
	info->width = 0;
	info->quest = 0;
	info->color = 0;
	info->length = 0;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	t_print	info;

	if (format == NULL)
		return (-1);
	initialize_info(&info);
	va_start(info.args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = eval_format(1, &info, format, i + 1);
		else
			info.length += write(1, &format[i], 1);
		i++;
	}
	va_end(info.args);
	return (info.length);
}
