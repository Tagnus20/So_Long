/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:56:51 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/13 16:04:59 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*c_src;
	char	*c_dst;
	size_t	i;

	i = 0;
	c_src = (char *) src;
	c_dst = (char *) dst;
	if (c_src == 0 && c_dst == 0)
		return (0);
	while (n > i)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	dst = (void *) c_dst;
	return (dst);
}
