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

void	ft_putnbrlonguint_fd(long int n, int fd)
{
    char c;

    if (n / 10 > 0)
    {
        ft_putnbr_fd(n / 10, fd);
        c = n % 10 + '0';
    }
    else
        c = n + '0';
    write(fd, &c, 1);
}

int ft_unsigned(long int u)
{
    if (u < 0)
    {
        ft_putnbrlonguint_fd(4294967296 + u, 1);   
         return(len_nb(4294967296 + u));
    }
    else 
    {
        ft_putnbrlonguint_fd(u, 1);
        return (len_nb(u));
    }
}
