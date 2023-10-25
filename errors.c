/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:42:07 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/17 20:13:09 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc, char *argv)
{
	char	*extension;

	if (argc < 2)
	{
		ft_printf("Error: map not found\n");
		exit(1);
	}
	if (argc > 2)
	{
		ft_printf("Error: many arguments\n");
		exit(1);
	}
	if (*argv == 0)
	{
		ft_printf("Error: null argument\n");
		exit(1);
	}
	extension = ft_strrchr(argv, '.');
	if (extension == NULL
		|| ft_strncmp(extension, ".ber", ft_strlen(extension)))
	{
		ft_printf("Error: wrong file extension\n");
		exit(1);
	}
}

void	read_map(char *argv, t_data *data)
{
	data->map = NULL;
	data->fd = open(argv, O_RDWR);
	if (data->fd == -1)
	{
		ft_printf("Error: no such file\n");
		exit(1);
	}
	while (data->fd > 0)
	{
		data->line = get_next_line(data->fd);
		if (!data->line)
			break ;
		if (data->map == NULL)
			data->map = ft_strdup(data->line);
		else
			data->map = ft_strjoin_free(data->map, data->line);
		free (data->line);
	}
	close(data->fd);
	if (!data->map)
	{
		ft_printf("Error: empty map\n");
		exit(1);
	}
}

void	check_errors(int argc, char *argv, t_data *data)
{
	check_args(argc, argv);
	read_map(argv, data);
}
