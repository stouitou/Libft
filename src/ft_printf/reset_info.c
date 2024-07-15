/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:33:23 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/12 14:12:45 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_info(t_print *info)
{
	info->conversion = 0;
	info->hash = 0;
	info->plus = 0;
	info->space = 0;
	info->width = 0;
	info->quest = 0;
	info->color = 0;
}
