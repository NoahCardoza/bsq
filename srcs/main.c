/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nocardoz <nocardoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 19:08:37 by nocardoz          #+#    #+#             */
/*   Updated: 2017/08/30 23:03:28 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"
/*
void	map_free(t_map *m)
{
	m->i = 0;
	free(m->key);
	free(m->dp);
	while (m->i < m->rows)
		free(m->data[m->i]);
	free(m->data);
	free(m);
}
*/
void	map_print(t_map *m)
{
	char *cols;

	m->i = 0;
	cols = malloc(sizeof(char) * (m->cols + 1));
	while (m->i < m->rows)
	{
		print_row(m, cols);
		m->i++;
	}
}

void	map_solve(int fd)
{
	t_map	*map;

	if ((map = map_init(fd)))
	{
		printf("VALID\n");
		map_print(map);
	}
	else
		write(1, "map error", 9);
	if (fd)
		close(fd);
	write(1, "\n", 1);
}

int		main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		while (*++argv)
			map_solve(open(*argv, S_IREAD));
	}
	else
		map_solve(0);
	return (0);
}
