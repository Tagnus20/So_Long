/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:56:45 by averdejo          #+#    #+#             */
/*   Updated: 2023/06/16 13:38:02 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *i)
{
	write(1, &c, 1);
	(*i)++;
}

void	ft_putstr(char *s, int *i)
{
	if (!s)
	{
		write(1, "(null)", 6);
		(*i) += 6;
	}
	else
	{
		while (*s)
		{
			ft_putchar(*s, i);
			s++;
		}
	}
}
