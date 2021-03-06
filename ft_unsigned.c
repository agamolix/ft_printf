/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:12:35 by atrilles          #+#    #+#             */
/*   Updated: 2022/04/22 15:40:25 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbrlonguint_fd(long int n, int fd)
{
	char	c;

	if (n / 10 > 0)
	{
		ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
	}
	else
		c = n + '0';
	write(fd, &c, 1);
}

int	ft_unsigned(unsigned int u)
{
	char		*res;
	int			len;
	long int	nb;

	nb = (long int)u;
	if (nb < 0)
		res = ft_utoa(4294967296 + nb);
	else
		res = ft_utoa(nb);
	ft_putstr_fd(res, 1);
	len = ft_strlen(res);
	free(res);
	return (len);
}
