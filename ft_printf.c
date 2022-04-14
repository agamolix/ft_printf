/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/02/08 16:14:27 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_print_s(va_list list, char format)
{
    int len;

    len = 0;
    if (format == '%')
        len = len_ft_putchar_fd('%', 1);
    else if (format == 'c')
        len = len_ft_putchar_fd(va_arg(list, int), 1);
    else if (format == 's')
        len = ft_s(va_arg(list, char *));
    else if (format == 'p')
        len = ft_hexa_s(va_arg(list, void *), 'x');
    else if (format == 'd' || format == 'i')
        len = ft_d(va_arg(list, int));
    else if (format == 'u')
        len = ft_unsigned(va_arg(list, long int));
    else if (format == 'x')
        len = ft_hexa_x(va_arg(list, int), 'x');
    else if (format == 'X')
        len = ft_hexa_x(va_arg(list, int), 'X');
    return len;
}

int ft_printf(const char *s, ...)
{
    va_list list;
    va_start(list, s);
    int len; 
    int res;

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