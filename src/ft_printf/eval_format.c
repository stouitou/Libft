/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:29:55 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/12 14:12:47 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_hash(t_print *info, const char *str, int i)
{
	info->hash = 1;
	i++;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static int	handle_plus(t_print *info, const char *str, int i)
{
	if (info->space)
		info->space = 0;
	info->plus = 1;
	i++;
	info->width = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static int	handle_space(t_print *info, const char *str, int i)
{
	if (info->plus)
		return (i + 1);
	info->space = 1;
	i++;
	info->width = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static int	handle_quest(t_print *info, const char *str, int i)
{
	info->quest = 1;
	i++;
	info->color = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int	eval_format(int fd, t_print *info, const char *str, int i)
{
	while (!ft_ischarset(str[i], CONVERSIONS))
	{
		if (str[i] == '#')
			i = handle_hash(info, str, i);
		else if (str[i] == '+')
			i = handle_plus(info, str, i);
		else if (str[i] == ' ')
			i = handle_space(info, str, i);
		else if (str[i] == '?')
			i = handle_quest(info, str, i);
		else
			i++;
	}
	checkcase(fd, info, str[i]);
	return (i);
}
