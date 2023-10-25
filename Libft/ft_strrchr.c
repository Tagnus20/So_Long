/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:06:18 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/13 16:07:10 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*chr;

	c = (unsigned char) c;
	len = 0;
	chr = (char *) s;
	while (chr[len] != '\0')
		len++;
	while (len >= 0)
	{
		if (chr[len] == c)
			return (chr + len);
		len--;
	}
	return (NULL);
}
