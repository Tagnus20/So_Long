/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:44:49 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/18 17:46:44 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	d;

	d.moves = 0;
	check_errors(argc, argv[1], &d);
	d.map_arg = ft_split(d.map, '\n');
	d.map_copy = ft_split(d.map, '\n');
	resolution(&d);
	valid_map(&d);
	find_pj(&d);
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, d.winy * 64, d.winx * 64, "So-Long");
	render_grass(&d);
	mlx_key_hook(d.win, dealkey, &d);
	mlx_hook(d.win, 17, (1L << 17), ft_close, d.mlx);
	mlx_loop(d.mlx);
	free(d.map);
	return (0);
}
