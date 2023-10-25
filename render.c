/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:44:41 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/17 20:12:34 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	resolution(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (data->map_arg[x] != 0)
		x++;
	data->winx = x;
	x = 0;
	while (data->map_arg[x][y] != 0)
		y++;
	data->winy = y;
}

void	assign_images(t_data *d)
{
	d->img_w = 64;
	d->img_h = 64;
	d->wall_p = mlx_xpm_file_to_image (d->mlx, WALL, &d->img_w, &d->img_h);
	d->floor_p = mlx_xpm_file_to_image (d->mlx, FLOOR, &d->img_w, &d->img_h);
	d->coin_p = mlx_xpm_file_to_image (d->mlx, COIN, &d->img_w, &d->img_h);
	d->exit_p = mlx_xpm_file_to_image (d->mlx, EXIT, &d->img_w, &d->img_h);
	d->pj_ptr = mlx_xpm_file_to_image(d->mlx, PJ, &d->img_w, &d->img_h);
	if (!d->pj_ptr || !d->exit_p || !d->coin_p || !d->floor_p || !d->wall_p)
	{
		ft_printf("Error: one or more images don't exist\n");
		exit(1);
	}
}

void	render_objetcs(t_data *d, int x, int y)
{
	if (d->map_arg[x][y] == '1')
		mlx_put_image_to_window (d->mlx, d->win, d->wall_p, d->j, d->i);
	else if (d->map_arg[x][y] == 'C')
		mlx_put_image_to_window (d->mlx, d->win, d->coin_p, d->j, d->i);
	else if (d->map_arg[x][y] == 'E')
		mlx_put_image_to_window (d->mlx, d->win, d->exit_p, d->j, d->i);
	else if (d->map_arg[x][y] == 'P')
	{
		d->pos_x = x;
		d->pos_y = y;
		mlx_put_image_to_window (d->mlx, d->win, d->pj_ptr,
			d->pos_y * 64, d->pos_x * 64);
	}
}

int	render_grass(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	d->i = 0;
	d->j = 0;
	assign_images(d);
	while (d->map_arg[x] != NULL)
	{
		while (d->map_arg[x][y] != '\0')
		{
			mlx_put_image_to_window (d->mlx, d->win, d->floor_p, d->j, d->i);
			render_objetcs(d, x, y);
			d->j = d->j + 64;
			y++;
		}
		d->j = 0;
		y = 0;
		d->i = d->i + 64;
		x++;
	}
	return (0);
}
