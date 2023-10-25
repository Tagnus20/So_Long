/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:30:13 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/13 16:06:36 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contador(char const *str, char c)
{
	int	resultado;
	int	i;

	resultado = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			resultado++;
		i++;
	}
	return (resultado);
}

static void	*ft_free(char **word)
{
	size_t	i;

	i = 0;
	while (word[i])
	{
		free (word[i]);
		i++;
	}
	free (word);
	return (NULL);
}

static char	**asignaarray(char const *s, char c, char **array)
{
	size_t	c_l;
	size_t	c_p;
	int		iaux;

	c_l = 0;
	c_p = 0;
	iaux = 0;
	while (s[c_p] != '\0')
	{
		if (s[c_p] != c && (s[c_p + 1] == c || s[c_p + 1] == '\0'))
		{
			array[iaux] = ft_substr(s, c_p - c_l, c_l + 1);
			if (!array[iaux])
				return (ft_free(array));
			c_l = 0;
			iaux++;
		}
		else if (s[c_p] != c)
			c_l++;
		c_p++;
	}
	array[iaux] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = (char **) malloc((contador(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = asignaarray(s, c, array);
	return (array);
}
