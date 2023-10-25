/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:44:37 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/18 17:40:49 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_movement(t_data *data, int new_x, int new_y)
{
	if (data->map_arg[new_x][new_y] == '1' ||
		(data->map_arg[new_x][new_y] == 'E' && data->coins != 0))
		return (1);
	data->moves++;
	ft_printf("%d\n", data->moves);
	if (data->map_arg[new_x][new_y] == 'E' && data->coins == 0)
	{
		ft_printf("\n***************\n* HAS GANADO! *\n***************\n");
		exit(1);
		free(data->map_copy);
	}
	else
	{
		if (data->map_arg[new_x][new_y] == 'C')
			data->coins--;
		mlx_clear_window(data->mlx, data->win);
		data->map_arg[data->pos_x][data->pos_y] = '0';
		data->map_arg[new_x][new_y] = 'P';
	}
	render_grass(data);
	return (0);
}

int	dealkey(int key, t_data *data)
{
	if (key == KEY_D)
		key_movement(data, data->pos_x, data->pos_y + 1);
	else if (key == KEY_A)
		key_movement(data, data->pos_x, data->pos_y - 1);
	else if (key == KEY_W)
		key_movement(data, data->pos_x - 1, data->pos_y);
	else if (key == KEY_S)
		key_movement(data, data->pos_x + 1, data->pos_y);
	else if (key == KEY_ESC)
		exit (1);
	return (0);
}
