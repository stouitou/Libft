/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:38:32 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/10 12:35:07 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_str_array_len(char **array)
{
	size_t	len;

	if (array == NULL)
		return (0);
	len = 0;
	while (array[len])
		len++;
	return (len);
}
