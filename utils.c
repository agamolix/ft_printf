/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:12:51 by atrilles          #+#    #+#             */
/*   Updated: 2022/04/20 15:38:20 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	count(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		if (n == INT_MIN)
			n = n + 1;
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	long int	nb;

	nb = n;
	res = malloc((count(n) + 1) * sizeof(char));
	if (res == 0)
		return (0);
	i = count((long int)n);
	res[i] = 0;
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[i - 1] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (res);
}

char	*ft_utoa(long int n)
{
	char		*res;
	int			i;
	long int	nb;

	nb = n;
	res = malloc((count(n) + 1) * sizeof(char));
	if (res == 0)
		return (0);
	i = count(n);
	res[i] = 0;
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[i - 1] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (res);
}
