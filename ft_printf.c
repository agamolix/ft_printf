/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:12:14 by atrilles          #+#    #+#             */
/*   Updated: 2022/04/20 15:42:37 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_s(va_list list, char format)
{
	int	len;

	len = 0;
	if (format == '%')
		len = len_ft_putchar_fd('%', 1);
	else if (format == 'c')
		len = len_ft_putchar_fd(va_arg(list, int), 1);
	else if (format == 's')
		len = ft_s(va_arg(list, char *), 1);
	else if (format == 'p')
		len = ft_hexa_s(va_arg(list, void *), 'x');
	else if (format == 'd' || format == 'i')
		len = ft_d(va_arg(list, int));
	else if (format == 'u')
		len = ft_unsigned(va_arg(list, unsigned int));
	else if (format == 'x')
		len = ft_hexa_x(va_arg(list, unsigned int), 'x');
	else if (format == 'X')
		len = ft_hexa_x(va_arg(list, unsigned int), 'X');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		len;
	int		res;

	va_start(list, s);
	len = 0;
	while (s[0])
	{
		if (s[0] != '%')
			len += len_ft_putchar_fd(s[0], 1);
		else if (s[1])
		{
			res = ft_print_s(list, s[1]);
			if (res < 0)
				return (-1);
			else
				len += res;
			s++;
		}
		s++;
	}
	va_end(list);
	return (len);
}
