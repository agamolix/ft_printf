/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/02/08 16:14:27 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int len_int_to_hexa_x (unsigned int u)
{
    int i;

    i = 0;
    if (u > 0)
    {
        while (u / 16 > 0)
        {
            i++;
            u /= 16;
        }
        i++;
    }
    return (i);
}

void   int_to_hexa_x(unsigned int u, char format)
{
    if (u > 0)
    {
        int_to_hexa_x(u / 16, format);
        if (u % 16 < 10)
            len_ft_putchar_fd(u % 16 + '0', 1);
        else 
        {
            if (format == 'x')
                len_ft_putchar_fd(u % 16 - 10 + 'a', 1);
            else
                len_ft_putchar_fd(u % 16 - 10 + 'A', 1);
        }
    }
}

int ft_hexa_x(unsigned int i, char format)
{
    if (i == 0)
    {
        write(1, "0", 1);
        return (1);
    }
    int_to_hexa_x(i, format);
    return(len_int_to_hexa_x(i));
}