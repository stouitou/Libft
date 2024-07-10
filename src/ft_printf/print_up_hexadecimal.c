/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_up_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:00:34 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/10 15:38:40 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_up_hexadecimal(int fd, t_print *info, size_t nbr)
{
	print_prefix(fd, info);
	puthexadecimal(fd, info, nbr, UP_HEXABASE);
	print_suffix(fd, info);
	info->flag = 0;
	info->color = 0;
}
