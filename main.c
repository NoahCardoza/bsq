/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nocardoz <nocardoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 19:08:37 by nocardoz          #+#    #+#             */
/*   Updated: 2017/08/30 16:02:10 by nocardoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

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

void	map_solve(int fd, int tbf)
{
	t_map	*map;
	char	*col;

	if ((map = map_init(fd)))
	{
		printf("VALID\n");
		col = malloc((map->cols + 1) * sizeof(char*));
		print_row(map, col);
		free(col);
		if (tbf)
			map_free(map);
	}
	else
	{
		write(1, "map error", 9);
		if (tbf)
			printf("LASTONE\n");
	}
	if (fd)
		close(fd);
	write(1, "\n", 1);
}

int		main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		while (*++argv)
			map_solve(open(*argv, S_IREAD), !*(argv + 1));
	}
	else
		map_solve(0, 0);
	return (0);
}
