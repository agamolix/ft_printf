/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/02/15 11:52:23 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <stdlib.h>

int ft_printf(const char *s, ...);
int ft_print_s(va_list list, char format);

int len_int_to_hexa_x (unsigned int u);
int len_int_to_hexa_s(uintptr_t u);
void    int_to_hexa_x(unsigned int u, char format);
void   int_to_hexa_s(uintptr_t u, char format);
int ft_hexa_s(void *s, char format);
int ft_hexa_x(unsigned int i, char format);

int ft_strlen(char *s);
void    ft_putstr_fd(char *s, int fd);
int len_ft_putchar_fd(char c, int fd);
int ft_s(char *s, int fd);

void    ft_putnbr_fd(int n, int fd);
int len_nb(long int n);
int ft_d (int i);

void    ft_putnbrlonguint_fd(long int n, int fd);
int ft_unsigned(unsigned int u);

int count(long int n);
char	*ft_itoa(int n);
char	*ft_utoa(long int n);


#endif
