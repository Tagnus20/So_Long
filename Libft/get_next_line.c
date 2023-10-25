/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:32:56 by averdejo          #+#    #+#             */
/*   Updated: 2023/10/17 15:04:57 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t	x;

	x = 0;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (x < (count * size))
	{
		tmp[x] = '\0';
		++x;
	}
	return (tmp);
}

char	*residue(char *reserve)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i])
	{
		free(reserve);
		return (NULL);
	}
	tmp = ft_calloc(ft_strlen(reserve) - i, sizeof(char));
	i++;
	while (reserve[i])
	{
		tmp[j++] = reserve[i++];
	}
	free(reserve);
	return (tmp);
}

char	*final_str(char *reserve)
{
	int		x;
	char	*final;

	x = 0;
	if (!reserve[x] || reserve[0] == '\0')
		return (NULL);
	while (reserve[x] != '\0' && reserve[x] != '\n')
		x++;
	if (reserve[x] == '\n')
		final = ft_calloc(x + 2, sizeof(char));
	else
		final = ft_calloc(x + 1, sizeof(char));
	if (!final)
		return (NULL);
	x = 0;
	while (reserve[x] != '\n' && reserve[x] != '\0')
	{
		final[x] = reserve[x];
		x++;
	}
	if (reserve[x] == '\n')
		final[x] = '\n';
	return (final);
}

char	*read_line(int fd, char *reserve)
{
	char	*buff;
	int		bytes_read;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(reserve);
			return (NULL);
		}
		buff[bytes_read] = 0;
		reserve = ft_strjoin_free (reserve, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char	*reserve;
	char		*line;
	int			x;

	x = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(reserve);
		reserve = NULL;
		return (NULL);
	}
	if (!reserve)
		reserve = ft_calloc(1, sizeof(char));
	reserve = read_line(fd, reserve);
	if (!reserve)
		return (NULL);
	line = final_str(reserve);
	reserve = residue(reserve);
	return (line);
}
