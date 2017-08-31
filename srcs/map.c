/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nocardoz <nocardoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 21:59:31 by nocardoz          #+#    #+#             */
/*   Updated: 2017/08/30 22:18:54 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

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
	create_dp(m);
	while (m->i < m->rows - 1)
	{
		if (!set_row(m, line) ||
			ft_get_line_buff(fd, &line, m->cols) != m->cols)
		{
			printf("FML\n");
			return (NULL);
		}
	}
	if (read(fd, NULL, 1))
		return (NULL);
	return (m);
	free(line);
}
