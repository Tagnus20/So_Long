/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:35:20 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/13 16:06:41 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*chr;
	int		counter;

	counter = 0;
	c = (unsigned char) c;
	chr = (char *) s;
	while (chr[counter] != c)
	{
		if (chr[counter] == '\0')
			return (NULL);
		chr++;
	}
	return (chr);
}
