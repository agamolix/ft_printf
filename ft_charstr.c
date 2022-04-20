/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:11:16 by atrilles          #+#    #+#             */
/*   Updated: 2022/04/20 15:46:15 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strlen(char *s)
{
	int	i;

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
		return ;
	}
	write(fd, s, ft_strlen(s));
}

int	len_ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_s(char *s, int fd)
{
	if (s == 0)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}
