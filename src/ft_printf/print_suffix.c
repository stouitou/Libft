/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_suffix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:03:00 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/10 15:36:09 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_suffix(int fd, t_print *info)
{
	if (info->flag == COLOR)
		ft_putstr_fd("\033[0m", fd);
}
