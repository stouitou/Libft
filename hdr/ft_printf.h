/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:34:02 by stouitou          #+#    #+#             */
/*   Updated: 2024/07/12 14:24:45 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# ifndef CONVERSIONS
#  define CONVERSIONS "cspdiuxX%"
# endif

# ifndef LOW_HEXABASE
#  define LOW_HEXABASE "0123456789abcdef"
# endif

# ifndef UP_HEXABASE
#  define UP_HEXABASE "0123456789ABCDEF"
# endif

typedef struct s_print
{
	va_list	args;
	int		conversion;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		quest;
	int		color;
	int		length;
}			t_print;

int		ft_printf(const char *format, ...);
int		ft_fprintf(int fd, const char *format, ...);
int		eval_format(int fd, t_print *info, const char *str, int i);
void	checkcase(int fd, t_print *info, char c);
void	print_prefix(int fd, t_print *info);
void	print_suffix(int fd, t_print *info);
void	puthexadecimal(int fd, t_print *info, unsigned long nbr, char *base);
void	print_char(int fd, t_print *info, int c);
void	print_str(int fd, t_print *info, char *str);
void	print_ptr(int fd, t_print *info, void *ptr);
void	print_nbr(int fd, t_print *info, int nbr);
void	print_unsigned(int fd, t_print *info, unsigned int nbr);
void	print_low_hexadecimal(int fd, t_print *info, unsigned long nbr);
void	print_up_hexadecimal(int fd, t_print *info, unsigned long nbr);
void	reset_info(t_print *info);

#endif
