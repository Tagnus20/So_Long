/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:00:57 by averdejo          #+#    #+#             */
/*   Updated: 2023/06/19 14:35:24 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putchar(char c, int *i);
void	ft_putstr(char *s, int *i);
int		ft_printf(const char *parameters, ...);
void	ft_putnbr(int n, int *i);
void	ft_unsigned(unsigned int n, int *i);
void	ft_hexadecimal(unsigned int number, int *i, char c);
void	ft_pointer(unsigned long long number, int *i);
void	ft_hexa_pointer(unsigned long long number, int *i);
void	ft_format(const char *parameters, va_list args, int *i);

#endif
