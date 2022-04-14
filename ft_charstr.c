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



int     ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
    if (s == 0)
    {
        write(fd, "NULL", 4);
        return;
    write(fd, s, ft_strlen(s));
}

int len_ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
    return (1);
}

int ft_s(char *s)
{
    if (s == 0)
    {
        write(fd, "NULL", 4);
        return (4);
    }
    write(fd, s, ft_strlen(s));
    return (ft_strlen(s));
}
