/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nocardoz <nocardoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 21:59:31 by nocardoz          #+#    #+#             */
/*   Updated: 2017/08/30 15:55:33 by nocardoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	map_print(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		if ((map->maxrow <= i && i < map->maxrow + map->maxqlen))
		{
			j = 0;
			write(1, map->data[i], map->maxcol);
			while (j++ < map->maxqlen)
				write(1, map->key + 2, 1);
			write(1, map->data[i] + map->maxcol + map->maxqlen,
				map->cols - map->maxcol - map->maxqlen);
		}
		else
			write(1, map->data[i], map->cols);
		write(1, "\n", 1);
		i++;
	}
}

t_map	*map_init(int fd)
{
	t_map	*m;
	char	*line;

	m = map_new();
	ft_get_line(fd, &m->key, 8);
	if (!(m->rows = ft_atoi(&m->key)) || ft_strlen(m->key) != 3 || 
		(*m->key == m->key[1] || m->key[2] == m->key[1]))
		return (NULL);
	m->data = malloc((m->rows + 1) * sizeof(char*));
	m->data[m->rows] = 0;
	if (!(m->cols = ft_get_line(fd, &line, m->rows / 4)))
		return (NULL);
	while (m->i < m->rows)
	{
		if (!set_row(m, line) ||
			ft_get_line_buff(fd, &line, m->cols) != m->cols)
			return (NULL);
	}
	if (read(fd, NULL, 1))
		return (NULL);
	return (m);
	free(line);
}
