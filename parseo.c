/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:01:50 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/17 20:21:30 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_pj(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map_arg[x] != '\0')
	{
		y = 0;
		while (data->map_arg[x][y] != '\0')
		{
			if (data->map_arg[x][y] == 'P')
			{
				check_coins(data, x, y);
				valid_coins(data);
				ft_free(data->map_copy);
				data->map_copy = ft_split(data->map, '\n');
				check_exit(data, x, y);
				valid_exit(data);
				ft_free(data->map_copy);
			}
			y++;
		}
		x++;
	}
}

void	check_exit(t_data *d, int x, int y)
{
	if (d->map_copy[x][y - 1] != '1' && d->map_copy[x][y - 1] != 'P' )
	{
		d->map_copy[x][y - 1] = 'P';
		check_exit(d, x, y - 1);
	}
	if (d->map_copy[x - 1][y] != '1' && d->map_copy[x - 1][y] != 'P')
	{
		d->map_copy[x - 1][y] = 'P';
		check_exit(d, x - 1, y);
	}
	if (d->map_copy[x][y + 1] != '1' && d->map_copy[x][y + 1] != 'P')
	{
		d->map_copy[x][y + 1] = 'P';
		check_exit(d, x, y + 1);
	}
	if (d->map_copy[x + 1][y] != '1' && d->map_copy[x + 1][y] != 'P')
	{
		d->map_copy[x + 1][y] = 'P';
		check_exit(d, x + 1, y);
	}
}

void	check_coins(t_data *d, int x, int y)
{
	if (d->map_copy[x][y - 1] != '1' && d->map_copy[x][y - 1] != 'P'
		&& d->map_copy[x][y - 1] != 'E')
	{
		d->map_copy[x][y - 1] = 'P';
		check_coins(d, x, y - 1);
	}
	if (d->map_copy[x - 1][y] != '1' && d->map_copy[x - 1][y] != 'P'
		&& d->map_copy[x - 1][y] != 'E')
	{
		d->map_copy[x - 1][y] = 'P';
		check_coins(d, x - 1, y);
	}
	if (d->map_copy[x][y + 1] != '1' && d->map_copy[x][y + 1] != 'P'
		&& d->map_copy[x][y + 1] != 'E')
	{
		d->map_copy[x][y + 1] = 'P';
		check_coins(d, x, y + 1);
	}
	if (d->map_copy[x + 1][y] != '1' && d->map_copy[x + 1][y] != 'P'
		&& d->map_copy[x + 1][y] != 'E')
	{
		d->map_copy[x + 1][y] = 'P';
		check_coins(d, x + 1, y);
	}
}

void	valid_exit(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map_copy[x] != '\0')
	{
		y = 0;
		while (data->map_copy[x][y] != '\0')
		{
			if (data->map_copy[x][y] == 'E')
			{
				ft_printf("Error: Invalid map\n");
				exit(1);
			}
			y++;
		}
		x++;
	}
}

void	valid_coins(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map_copy[x] != '\0')
	{
		y = 0;
		while (data->map_copy[x][y] != '\0')
		{
			if (data->map_copy[x][y] == 'C')
			{
				ft_printf("Error: you can't reach all the collectibles\n");
				exit(1);
			}
			y++;
		}
		x++;
	}
}
