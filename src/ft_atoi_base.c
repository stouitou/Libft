/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:54:26 by stouitou          #+#    #+#             */
/*   Updated: 2024/06/26 10:10:52 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (false);
	i = 0;
	while (base[i])
	{
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static int	ft_indexbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	result;
	int	sign;
	int	len;
	int	i;

	if (!valid_base(base))
		return (0);
	result = 0;
	sign = 1;
	len = ft_strlen(base);
	i = 0;
	while (ft_isspace(nbr[i]))
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_ischarset(nbr[i], base))
	{
		result = result * len + ft_indexbase(nbr[i], base);
		i++;
	}
	return (sign * result);
}
