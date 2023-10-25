/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:18:25 by averdejo          #+#    #+#             */
/*   Updated: 2023/09/27 17:04:27 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char *parameters, va_list args, int *i)
{
	if (*parameters == 'c')
		ft_putchar(va_arg(args, int), i);
	else if (*parameters == 'd' || *parameters == 'i')
		ft_putnbr(va_arg(args, int), i);
	else if (*parameters == 's')
		ft_putstr(va_arg(args, char *), i);
	else if (*parameters == 'u')
		ft_unsigned(va_arg(args, unsigned int), i);
	else if (*parameters == 'x' || *parameters == 'X')
		ft_hexadecimal(va_arg(args, unsigned int), i, *parameters);
	else if (*parameters == 'p')
		ft_pointer(va_arg(args, unsigned long long), i);
	else if (*parameters == '%')
	{
		write(1, "%%", 1);
		(*i)++;
	}
	else
	{
		write(1, parameters, 1);
	}
}

int	ft_printf(const char *parameters, ...)
{
	va_list	args;
	int		i;

	va_start(args, parameters);
	i = 0;
	while (*parameters)
	{
		if (*parameters == '%')
		{
			parameters++;
			ft_format(parameters, args, &i);
			parameters++;
		}
		else
		{
			write(1, parameters++, 1);
			(i)++;
		}
	}
	va_end(args);
	return (i);
}
