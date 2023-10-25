/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:55:18 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/13 16:06:44 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cs1;
	size_t	len;

	len = ft_strlen(s1) + 1;
	cs1 = (char *) malloc(len * sizeof(char));
	if (!cs1)
		return (NULL);
	ft_memcpy(cs1, s1, len);
	return (cs1);
}
