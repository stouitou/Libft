/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:29:55 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/10 15:51:25 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	eval_format(int fd, t_print *info, const char *str, int i)
{
	while (!ft_ischarset(str[i], CONVERSIONS))
	{
		if (str[i] == '?')
		{
			info->flag = COLOR;
			i++;
			info->color = ft_atoi(&str[i]);
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	checkcase(fd, info, str[i]);
	return (i);
}
