/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:25:20 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/13 20:25:21 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **word)
{
	int	i;

	i = 0;
	while (word[i])
	{
		free (word[i]);
		i++;
	}
	free (word);
}

int	ft_close(t_data *vars)
{
	if (!vars)
		exit(1);
	exit(1);
}
