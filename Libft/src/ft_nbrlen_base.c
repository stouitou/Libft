/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:37:47 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/09 15:48:38 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen_base(long int n, char *base)
{
	size_t	len;
	int		base_len;

	len = 1;
	base_len = (long int)ft_strlen(base);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}
