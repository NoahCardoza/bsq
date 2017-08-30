/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nocardoz <nocardoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 04:06:45 by nocardoz          #+#    #+#             */
/*   Updated: 2017/08/30 04:06:49 by nocardoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_map	*map_init(int fd)
{
	t_map	*m;
	char 	**b;

	m = malloc(sizeof(t_map));
	ft_get_line(fd, &m->key, 16);
	if (!(m->rows = ft_atoi(&m->key)) || ft_strlen(m->key) != 3)
		return (NULL);
	b = (m->data = malloc((m->rows + 1) * sizeof(char*)));
	b[m->rows] = 0;
	m->cols = ft_get_line(fd, b, m->rows / 4);
	while (b - m->data < m->rows - 1)
	{
		while (**b)
			if (index_of(*((*b)++), m->key) == -1)
				return (NULL);
		if (ft_get_line_n(fd, ++b, m->cols) != m->cols)
			return (NULL);
	}
	return (m);
}
