/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:02:38 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/13 16:04:43 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*chr;
	unsigned char	x;

	x = (unsigned char) c;
	chr = (unsigned char *) s;
	while (n)
	{
		if (*chr == x)
			return ((void *)chr);
		chr++;
		n--;
	}
	return (NULL);
}
