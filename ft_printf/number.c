/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:57:00 by averdejo          #+#    #+#             */
/*   Updated: 2023/06/16 13:39:20 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *i)
{
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		(*i)++;
		(*i)++;
		n = 147483648;
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		(*i)++;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, i);
		ft_putnbr(n % 10, i);
	}
	if (n <= 9)
		ft_putchar((n) + '0', i);
}

void	ft_unsigned(unsigned int n, int *i)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, i);
		ft_putnbr(n % 10, i);
	}
	if (n <= 9)
		ft_putchar((n) + '0', i);
}

void	ft_hexadecimal(unsigned int number, int *i, char c)
{
	const char	*base;
	const char	*base2;

	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (number >= 16)
	{
		ft_hexadecimal(number / 16, i, c);
		ft_hexadecimal(number % 16, i, c);
	}
	if (number < 16)
	{
		if (c == 'x')
			ft_putchar(base[number], i);
		else if (c == 'X')
			ft_putchar(base2[number], i);
	}
}

void	ft_hexa_pointer(unsigned long long number, int *i)
{
	const char	*base;

	base = "0123456789abcdef";
	if (number >= 16)
	{
		ft_hexa_pointer(number / 16, i);
		ft_hexa_pointer(number % 16, i);
	}
	if (number < 16)
		ft_putchar(base[number], i);
}

void	ft_pointer(unsigned long long number, int *i)
{
	write(1, "0x", 2);
	(*i) += 2;
	ft_hexa_pointer(number, i);
}
