/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:20:19 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/18 17:42:58 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_D 2
# define KEY_S 1
# define KEY_A 0
# define KEY_W 13
# define KEY_ESC 53
# define WALL "../SoLong/textures/Stone.xpm"
# define FLOOR "../SoLong/textures/Grass.xpm"
# define COIN "../SoLong/textures/Egg.xpm"
# define EXIT "../SoLong/textures/Nest.xpm"
# define PJ "../SoLong/textures/Dino.xpm"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*pj_ptr;
	void	*floor_p;
	void	*wall_p;
	void	*coin_p;
	void	*exit_p;
	int		img_w;
	int		img_h;
	int		winx;
	int		winy;
	int		pos_x;
	int		pos_y;
	int		fd;
	char	*line;
	char	*map;
	char	**map_copy;
	char	**map_arg;
	int		moves;
	int		coins;
	int		i;
	int		j;
}				t_data;

void	resolution(t_data *data);
int		render_grass(t_data *d);
void	render_objetcs(t_data *d, int x, int y);
void	assign_images(t_data *d);
int		dealkey(int key, t_data *data);
int		ft_close(t_data *vars);
void	is_square(t_data data);
void	valid_letters(t_data d);
void	no_repetitions(t_data data);
void	coin_counter(t_data *data);
void	valid_map(t_data *data);

void	find_pj(t_data *data);
void	check_exit(t_data *d, int x, int y);
void	valid_exit(t_data *data);
void	check_coins(t_data *d, int x, int y);
void	valid_coins(t_data *data);

void	ft_free(char **word);

void	check_errors(int argc, char *argv, t_data *data);
void	check_args(int argc, char *argv);
void	read_map(char *argv, t_data *data);

int		key_movement(t_data *data, int new_x, int new_y);

#endif
