/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:12:05 by atrilles          #+#    #+#             */
/*   Updated: 2022/04/20 15:43:37 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, "8", 1);
	}
	else if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n / 10 > 0)
	{
		ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
	}
	else
		c = n + '0';
	write(fd, &c, 1);
}

int	len_nb(long int n)
{
	int	res;

	res = 0;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		res = 1;
		n = -n;
	}
	while (n / 10 > 0)
	{
		res += 1;
		n /= 10;
	}
	res++;
	return (res);
}

int	ft_d(int i)
{
	char	*res;
	int		len;

	res = ft_itoa(i);
	ft_putstr_fd(res, 1);
	len = ft_strlen(res);
	free(res);
	return (len);
}
