/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:41:55 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/17 20:21:59 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_square(t_data d)
{
	int	x;
	int	y;

	x = 0;
	while (d.map_arg[x] != '\0')
	{
		y = 0;
		while (d.map_arg[x][y] != '\0')
		{
			if (d.map_arg[x][0] != '1' || d.map_arg[x][d.winy - 1] != '1')
			{
				ft_printf("Error: map without walls or not rectangle\n");
				exit (1);
			}
			if (d.map_arg[0][y] != '1' || d.map_arg[d.winx - 1][y] != '1')
			{
				ft_printf("Error: map without walls or not rectangle\n");
				exit (1);
			}
			y++;
		}
		x++;
	}
}

void	valid_letters(t_data d)
{
	int	x;
	int	y;

	x = 0;
	while (d.map_arg[x] != '\0')
	{
		y = 0;
		while (d.map_arg[x][y] != '\0')
		{
			if (d.map_arg[x][y] != '1' && d.map_arg[x][y] != 'P'
			&& d.map_arg[x][y] != 'C' && d.map_arg[x][y] != '0'
			&& d.map_arg[x][y] != 'E')
			{
				ft_printf("Error: wrong characters in the map\n");
				exit(1);
			}
			y++;
		}
		x++;
	}
}

void	no_repetitions(t_data data)
{
	int	n;
	int	x;
	int	y;
	int	e;

	n = 0;
	x = -1;
	e = 0;
	while (data.map_arg[++x] != '\0')
	{
		y = -1;
		while (data.map_arg[x][++y] != '\0')
		{
			if (data.map_arg[x][y] == 'P')
				n++;
			if (data.map_arg[x][y] == 'E')
				e++;
		}
	}
	if (n != 1 || e != 1)
	{
		ft_printf("Error: check Pj and exit\n");
		exit(1);
	}
}

void	coin_counter(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	data->coins = 0;
	while (data->map_arg[x] != NULL)
	{
		y = 0;
		while (data->map_arg[x][y] != '\0')
		{
			if (data->map_arg[x][y] == 'C')
				data->coins++;
			y++;
		}
		x++;
	}
	if (data->coins == 0)
	{
		ft_printf("Error: no collectibles\n");
		exit(1);
	}
}

void	valid_map(t_data *data)
{
	if (data->winx > 20 || data->winy > 40)
	{
		ft_printf("Error: map size too big\n");
		exit(1);
	}
	is_square(*data);
	valid_letters(*data);
	no_repetitions(*data);
	coin_counter(data);
}
