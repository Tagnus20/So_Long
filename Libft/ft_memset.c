/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:20:36 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/13 16:05:05 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;

	a = (unsigned char *) b;
	i = 0;
	while (len > i)
	{
		a[i] = (unsigned char) c;
		i++;
	}
	b = (void *) a;
	return (b);
}
